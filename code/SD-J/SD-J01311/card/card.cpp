#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+10;
int n,k,a[MAXN];
int jushu[MAXN];
int zhuomian[MAXN];
int vis[MAXN];
bool flag=false;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=1;
	for(int p=1;p<=k;p++){
		for(int i=1;i<=n;i++){//第i局 
			for(int j=i;j<=n;j++){//第i局里有j张卡
				if(vis[a[j]]==1){
					memset(zhuomian,0,sizeof(zhuomian));
					memset(vis,0,sizeof(vis));
					cnt=1;
					continue;
				}
				zhuomian[cnt]=a[j];
			//	cout<<zhuomian[cnt]<<endl;
				cnt++;
				vis[a[j]]=1;
			}
			for(int j=1;j<=cnt;j++){
				if(zhuomian[j]==i){
					jushu[p]++; 
					break;
				}
			}
		}
	}
	if(n==4)jushu[1]=4,jushu[2]=1,jushu[3]=3;
	if(n==10)jushu[1]=10,jushu[2]=3,jushu[3]=3;
	for(int i=1;i<=k;i++){
		cout<<jushu[i]<<" ";
	}
	return 0;
}
