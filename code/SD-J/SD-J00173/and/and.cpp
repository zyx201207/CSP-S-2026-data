#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans,p[35],k[200005],s[200005],ff,cnt;
vector<int> v[35];
void f(int k,int h){
	int g=0;
	while(k){
		if(k&1){
			p[g]++;
			v[g].push_back(h);
		}
		k>>=1;
		g++;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)f(a[i],i);
	for(int i=30;i>=0;i--){
		if(p[i]<m)continue;
		if(ff==0){
			ff=1;
			for(auto j:v[i])k[j]=1;
			continue;
		}
		cnt=0;
		for(int j=1;j<=n;j++)s[j]=0;
		for(auto j:v[i])s[j]=k[j],cnt+=k[j];
		if(cnt>=m)for(int j=1;j<=n;j++)k[j]=s[j];
	}
	ff=0;
	for(int i=1;i<=n;i++){
		if(k[i]==0)continue;
		if(ff==0){
			ans=a[i],ff=1;
			continue;
		}
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
