#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N];
stack<int>stk;
bool b[M];
int c[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,false,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==false){
				b[a[j]]=true;
				stk.push(a[j]);
			}
			else{
				while(stk.top()!=a[j]){
					b[stk.top()]=false;
					stk.pop();
				}
			}
		}
		while(!stk.empty()){
			c[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
