#include<bits/stdc++.h>
using namespace std;
int tong[300010];
int a[500010];
int now[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(tong,0,sizeof(tong));
	memset(a,0,sizeof(a));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int z=1,y=1;
		memset(now,-1,sizeof(now));
		map<int,int> mp;
		now[y]=a[i];
		mp[a[i]]++;
		for(int j=i+1;j<=n;j++){
			if(mp[a[j]]!=0){
				y--; 
				while(now[y]!=a[j])y--;
				y--;
			}
			mp[a[j]]=0;
			now[++y]=a[j];
			mp[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			if(mp[a[j]]!=0){
				tong[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
}
