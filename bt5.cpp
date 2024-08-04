#include <iostream>
#include <vector>
#include <stack>

class QueueUsingTwoStack{
private:
	std::stack<int> stack1,stack2;
	void transferstack1tostack2(){
		while(!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	
public:
	void enqueue(int x){
		stack1.push(x);
	}
	
	void dequeue(){
		if(stack2.empty()){
			transferstack1tostack2();
		}
		if(!stack2.empty()){
			stack2.pop();
		}
	}
	
	void printfront(){
		if(stack2.empty()){
			transferstack1tostack2();
		}
		if(!stack2.empty()){
			std::cout<< stack2.top() << std::endl;
		}
	}
};

void processqueries(int q, std::vector<std::vector<int>>& queries){
	QueueUsingTwoStack e;
	
	for(const auto&query : queries){
		if(query[0] == 1){
			e.enqueue(query[1]);
		}
		if(query[0] == 2){
			e.dequeue();
		}
		if(query[0] == 3){
			e.printfront();
		}
	}
}

int main(){
	int q;
	std::cin>>q;
	std::vector<std::vector<int>> queries(q);
	for(int i=0;i<q;i++){
		int type;
		std::cin>>type;
		queries[i].push_back(type);
		if(type == 1){
			int x;
			std:: cin>>x;
			queries[i].push_back(x);
		}
	}
	processqueries(q,queries);
	return 0;
}
