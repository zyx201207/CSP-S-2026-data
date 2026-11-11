#include<bits/stdc++.h>
using namespace std;
#define lint long long
lint n,m,a[500010],ans,cnt,ji,cn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	lint l,r;
	ans=1;
	cn=1;
	l=1;
	r=2;
	cnt=m;
	while(r<=n){
		if(cnt-(a[r]-a[r-1])*(r-l)>=0){
			cnt-=(a[r]-a[r-1])*(r-l);
			cn++;
			ans=max(cn,ans);
			r++;
		}
		else{
			cnt+=a[r-1]-a[l];
			cn--;
			l++;
		}
	} 
	cout<<ans;
	return 0;
} 
