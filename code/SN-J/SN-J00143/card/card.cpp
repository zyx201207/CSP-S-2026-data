#include<bits/stdc++.h>
using namespace std ;
int a[5005],jf[5005];
bool vis[5005],op;
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]; 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			op=false;
			if(vis[a[j]]==false){
				vis[a[j]]=true;
			}else{
				while(!q.empty()){
					if(q.top()==a[j]){
						op=true;
					}
					vis[q.top()]=false;
					q.pop();
					if(op==true)break;
				}
			}
			vis[a[j]]=true;
			q.push(a[j]);
		}
		while(!q.empty()){
			jf[q.top()]++;
			q.pop();
		}
		for(int j=i;j<=n;j++)vis[a[j]]=false;
	}
	for(int i=1;i<=m;i++)cout<<jf[i]<<" ";
	return 0;
} 
//10 3
//3 1 2 1 3 2 3 1 2 1



