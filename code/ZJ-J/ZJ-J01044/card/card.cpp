#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mnxt[500005],num[300005],ans[500005];
int main(){
	//freopen("card.in","w",stdin);
	//ferpoen("card.out","r",stfout);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(mnxt,0x3f,sizeof(mnxt));
	cin>>n>>m;
	map<int,int>mp;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mp.count(a[i])){
			mnxt[mp[a[i]]]=i;
			mp[a[i]]=i;
		}
		else mp[a[i]]=i;
		num[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		map<int,bool>vis;
		int j=i;
		while(j<=n){
			if(mnxt[j]<=n){
				j=mnxt[j];
				continue;
			}
			if(!vis.count(j)){
				ans[j]++;
				vis[j]=true;
			}
			j++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
