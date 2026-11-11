#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300007];
int q[300007],top;
int vis[300007],bo[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=1;j<=n;j++){
			q[j]=0;
		} 
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			int last=0;
			++top,q[top]=a[j];
			for(int k=1;k<top;k++){
				if(q[k]==q[top]) last=k;
			}
			if(last!=0){
				for(int k=last;k<top;k++){
					q[k]=0;
				}
			}
//			for(int k=1;k<=top;k++){
//				cout<<q[k]<<' ';
//			}
//			cout<<'\n';
		}
		for(int j=1;j<=top;j++){
			if(q[j]) bo[q[j]]++;
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++) cout<<bo[i]<<' '; 
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
