#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,m,a[N],b[N],d;
map<int,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=d;j++) if(b[j]==a[i]) d=j-1;
			b[++d]=a[i];
		}
		for(int j=1;j<=d;j++) if(b[j]<=m) mp[b[j]]++;
	}
	
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it){
		cout<<it->second<<" ";
	}
	return 0;
}
