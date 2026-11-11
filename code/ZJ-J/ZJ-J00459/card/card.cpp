#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
int a[500005]; 
int cnt[300005];
int main(){
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
for(int j=1;j<=n;j++){
	int x[500005];
	memset(x,0,sizeof 0);
	map<int,int>mp;
	for(int i=j;i<=n;i++){
		if(mp.find(a[i])!=mp.end()){
//			cout<<mp[a[i]]<<" ";
			for(int k=mp[a[i]];k<i;k++){
				mp.erase(x[k]);
				x[k]=-1;
			}
			mp[a[i]]=i-j+1;
			x[i-j+1]=a[i];
		}
		else{
			mp[a[i]]=i-j+1;
			x[i-j+1]=a[i];
		}
//		for(int k=1;k<=i;k++)cout<<x[k]<<" ";
//		cout<<"\n";
	}
	for(auto it:mp){
//		cout<<it.first<<" ";
		cnt[it.first]++;
	}
//	cout<<"\n";
}
for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";

return 0;
}
