#include<bits/stdc++.h>
using namespace std;
struct card {
	int place,s;
	bool flag;
};
int n,p=0;
card q[100001];
stack<int>st;
int ans[100001];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(q[a].flag==1){
			while(q[st.top()].s!=a){
				
				st.pop();
				p--;
			}
			st.pop();
			p--;
		}
		else {
			st.push(a);
			q[a].flag=1;
			q[a].place=p;
			q[a].s=a;
		}
	}
	int i=0;
	while(!st.empty()){
		ans[++i]=st.top();
		st.pop();
	}
	for(int j=1;j<=i;j++)cout<<ans[j]<<' ';
	return 0;
}
