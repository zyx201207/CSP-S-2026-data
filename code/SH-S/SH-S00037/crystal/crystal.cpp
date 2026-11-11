#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[500005],d[500005];
int j=1,ans;
string sm;
__int128 m,k;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>sm;
	for(int i=0;i<sm.length();++i)
		m=m*10+sm[i]-'0';
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		d[i]=a[i]-a[i-1];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i,++j){
		k+=(j-1)*d[i];
		while(k>m&&j>=0){
			j--;
			k-=a[i]-a[i-j];
		}
		ans=max(ans,j);
	}
	cout<<ans<<"\n";
	return 0;
}

