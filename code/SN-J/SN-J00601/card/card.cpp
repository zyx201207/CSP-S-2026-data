#include<bits/stdc++.h>
using namespace std;
bitset<500005>has;
int ans[500005];
int n,m;
int arr[500005];
stack<int>stk;
void sol(int st){
	has.reset();
	for(int i=st;i<=n;i++){
		if(!has[arr[i]]){
			stk.push(arr[i]);
			has[arr[i]]=1;
		}
		else{
			 while(stk.top()!=arr[i]){
			    has[stk.top()]=0;
			 	stk.pop();
			 }
			 stk.pop();
			 stk.push(arr[i]);
		}
	}
    
	while(!stk.empty()){
		ans[stk.top()]++;
		stk.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
	for(int i=1;i<=n;i++)sol(i);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
