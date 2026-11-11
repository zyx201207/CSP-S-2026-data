#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],ans,r;
char w[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>w[i];
	}
	r=n;
	for(ll i=1;i<=n&&i<r;i++,r--){
		if(a[i]==a[r]){
			if(w[i]!=w[r])ans+=a[i];
		}else if(a[i]<a[r]){
			a[r]-=a[i];
			if(w[i]!=w[r])ans+=a[i];
			r++;
		}else{
			a[i]-=a[r];
			if(w[i]!=w[r])ans+=a[r];
			i--;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
