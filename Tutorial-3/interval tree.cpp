// interval tree
// language- C++
#include<bits/stdc++.h>
using namespace std;

int type=1;

int maxi(int a, int b){
	return (a>b)?a:b;
}

struct node{
	int low,high,max;
	node* left_child;
	node* right_child;
};

node *root=new node();

void insert(node *temp_node){
	temp_node->max=temp_node->high;
	if(root==NULL){
		root=temp_node;
		root->left_child=NULL;
		root->right_child=NULL;
		return;
	}
	node* current=root;
	while(true){
		current->max=maxi(current->max, temp_node->max);
		if(temp_node->low <= current->low){
			if(current->left_child) current=current->left_child;
			else{
				current->left_child=temp_node;
				break;
			}
		}
		else{
			if(current->right_child) current=current->right_child;
			else{
				current->right_child=temp_node;
				break;
			}
		}
	}
}

//to check whether the two intervals are same or not
bool check(node* node1, node* node2){
	if(node1->low==node2->low && node1->high==node2->high) return true;
	return false;
}
void change(node* node1, node* node2){
	node1->low=node2->low;
	node1->high=node2->high;
}

void remove(node* current, node* parent, bool head){
	//head=true here indicates it is the root node
	int child=0;
	bool left=false, right=false;
	if(current->low <= parent->low) left=true;
	else right=true;

	if(current->left_child) child++;
	if(current->right_child) child++;
	
	if(child==0){
		if(head){
			parent=NULL;
			return;
		}
		if(left) parent->left_child=NULL;
		else parent->right_child=NULL;
	}
	else if(child==1){
		if(head){
			if(current->left_child) root=root->left_child;
			else root=root->right_child;
			return;
		}
		if(left){
			if(current->right_child) parent->left_child=current->right_child;
			else parent->left_child=current->left_child;
		}
		else{
			if(current->right_child) parent->right_child=current->right_child;
			else parent->right_child=current->left_child;
		}
	}
	else{
		node* temp=current;
		temp=temp->left_child;
		if(temp->right_child){
			while(temp->right_child){
				parent=temp;
				temp=temp->right_child;
			}
			change(current, temp);
			parent->right_child=NULL;
		}
		else{
			change(current, temp);
			remove(temp, current, false);
		}
	}
}

void delete_interval(node* temp_node){
	node* current=root;
	node *parent=root;
	//eleminate the case when we have to delete the root node itself
	//take care of that later
	while(true){
		if(current==NULL){
			cout<<"The interval you requested to delete does not exist.\n";
			break;
		}
		if(temp_node->low < current->low){
			parent=current; current=current->left_child;
		}
		else if(temp_node->low > current->low){
			parent=current; current=current->right_child;
		}
		else{
			remove(current, parent, false);
			break;
		}
	}
}

//in-order traversal
void show(node* current){
	if(current==NULL) return;
	show(current->left_child);
	cout<<current->low<<" ";
	show(current->right_child);
}

node* search(node* temp_node){
	node* current=root;
	while(true){
		if(current==NULL){
			cout<<"No overlapping interval found.\n";
			return NULL;
		}
		if((temp_node->low <= current->high) && (temp_node->high >= current->low)){
			cout<<"An overlapping node found.\n";
			return current;
		}
		if(current->left_child){
			if(current->left_child->max >= temp_node->low) current=current->left_child;
		}
		else if(current->right_child){
			if(current->right_child->max >= temp_node->low) current=current->right_child;
		}
		else{
			cout<<"No overlapping interval found.\n";
			return NULL;
		}

	}
}

int main(){
	cout<<"Follow the the following instructions for input:\n";
	cout<<"To insert an interval: \"1 low_value high_Value\"\n";
	cout<<"To delete an interval: \"2 low_value high_Value\"\n";
	cout<<"To search an interval-overlap: \"3 low_value high_Value\"\n";
	cout<<"To stop the execution: \"-1\"\n";
	root=NULL;
	while(type!=-1){
		node *temp=new node();
		cin>>type;
		if(type==1 || type==2 || type==3){
			cin>>temp->low>>temp->high;
			while(temp->high < temp->low){
				cout<<"Not the valid interval. Enter the interval values again:\n";
				cin>>temp->low>>temp->high;
			}
		}
		if(type==1){
			insert(temp);
		}
		else if(type==2){
			delete_interval(temp);
		}
		else if(type==3){
			node* x=new node();
			x=search(temp);
			cout<<x->low<<endl;
		}
		else if(type!=-1){
			cout<<"Invalid input, please give input again.\n";
		}
		//show(root); cout<<endl;
	}
	return 0;
}