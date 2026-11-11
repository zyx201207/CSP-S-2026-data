#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],b[300100];
bool mark[300100];
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!mark[a[j]]){
				q.push(a[j]);
				mark[a[j]]=true;
			}else{
				while(q.top()!=a[j]){
					mark[q.top()]=false;
					q.pop();
				}
			} 
		}
		for(int j=1;j<=m;j++){
			if(mark[j]==true){
				b[j]++;
				mark[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

