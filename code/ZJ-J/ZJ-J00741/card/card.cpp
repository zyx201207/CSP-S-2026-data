#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000001];
int cnt[1000001];
int f[1000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int>q;
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				q.push(a[j]);
				f[a[j]]=1;
			}else{
				while(q.top()!=a[j]){
					f[q.top()]=0;
					q.pop(); 
				}
			}
			while(a[j]==a[j+1])j++;
		}
		for(int i=1;i<=m;i++){
			cnt[i]+=f[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
