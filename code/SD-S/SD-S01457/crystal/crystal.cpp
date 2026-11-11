#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
const int N=5e5+5;
ll a[N],n,m,ma,id,l,ri,ans;
map<ll,ll>mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(re int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+1+n);
	l=1;ll res=0,now=m;
	for(re int i=1;i<=n;i+=mp[a[i]]){
		now-=res*(a[i]-a[i-1]);
		res+=mp[a[i]];
		while(now<0){
			now+=a[i]-a[l];
			res--;
			l++;
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}

