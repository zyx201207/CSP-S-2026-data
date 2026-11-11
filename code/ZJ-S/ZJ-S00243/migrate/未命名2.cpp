#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x;
	int t;
	int now;
	bool operator<(const Node &b){
		return t>b.t;
	}
};
bool operator<(const Node &a,const Node &b){
	return a.t>b.t;
}
int main(){
	const Node a={1,2,3};
	const Node b={1,7,5};
	cout<<(a<b);
}