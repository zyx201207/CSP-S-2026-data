#include<bits/stdc++.h>
using namespace std;
int n,m,maxnn=-100;
priority_queue<int>q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		q.push(a);
	}
	while(m-=1&&!q.empty()){
		if(m==1){
			q.pop();
			cout<<q.top();
		}
		q.pop();
	}
	return 0;
}