#include<bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
typedef long long ll;
int v[2000005];
char c[2000005];
ll ans,n,cnt,now;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
//		cout<<l<<' '<<c[l]<<' '<<v[l]<<' '<<r<<' '<<c[r]<<' '<<v[r]<<' '<<min(v[l],v[r])<<' ';
		int i=min(v[l],v[r]);
		if(c[l]!=c[r]) ans+=i;
		v[l]-=i;
		v[r]-=i;
		if(v[l]==0) l++;
		if(v[r]==0) r--;
		//cout<<ans<<'\n';
	}
	cout<<ans;
	return 0;//×¢ÊÍ 
} 
