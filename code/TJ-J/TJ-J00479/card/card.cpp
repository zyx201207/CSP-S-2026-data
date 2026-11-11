#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],ans[N];
map<ll,ll>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>a[i];
		x=a[i];
		if(mp[x]==0)mp[x]=i;
		else {
			for(int i=1;i<=m;i++)if(mp[i])mp[i]=0;
			mp[x]=1;
		}
	}for(int i=1;i<=m;i++)ans[i]+=(mp[i]>0);
	for(int i=2;i<=n;i++){
		for(int k=1;k<=n;k++)mp[k]=0;
		for(int j=i;j<=n;j++){
			int x=a[j];
			if(mp[x]==0)mp[x]=j;
			else {
				for(int j=1;j<=m;j++)if(mp[j])mp[j]=0;
				mp[x]=1;
			}
		}for(int j=1;j<=m;j++)ans[j]+=(mp[j]>0);
	}for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
