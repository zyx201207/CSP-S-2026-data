#include<bits/stdc++.h>
using namespace std;
int a[500050];
int ans[300050];
int n,m;
stack<int>stk;
bool instk[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int N=1;N<=n;N++){
		for(int i=N;i<=n;i++){
			int x=a[i];
			if(!instk[x]){
				stk.push(x);
				instk[x]=1;
			}else{
				while(!stk.empty()&&stk.top()!=x){
					int t=stk.top();
					stk.pop();
					instk[t]=0;
					if(t==x)break;
				}
			}
		}
		for(int j=1;j<=m;j++)ans[j]+=instk[j];
		while(!stk.empty())stk.pop();
		for(int i=1;i<=m;i++)instk[i]=0;
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
}

