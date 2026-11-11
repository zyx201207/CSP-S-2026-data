#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;

bool vis[N];
int a[N],d[N],xb[N],h[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				xb[a[j]]=j;
				d[j]=a[j];
			}else{
				for(int k=xb[a[j]];k<j;k++){
					vis[a[k]]=0;
					d[k]=0;
					xb[a[k]]=0;
				}
				d[j]=a[j];
				vis[a[j]]=1;
			}
		}
//		cout<<"第"<<i<<"局结束了"<<"\n";
		for(int j=1;j<=n;j++){
			h[d[j]]++;
//			if(d[j]!=0){
//				cout<<d[j]<<" ";
//			}
		}
//		cout<<"\n";
	}
	for(int x=1;x<=m;x++){
		cout<<h[x]<<" ";
	}
	return 0;
}


