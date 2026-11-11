#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
const int mo=1e9+7;
ll mod(ll x){
	return (x%mo+mo)%mo;
}
const int N=2e5+5;
int n,a[N],L,ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++) L+=a[i];
	int mid=L/2;
	int l=min(a[1],mid),r=min(a[n],mid);
	if(c[1]!=c[n])ans=min(l,r);
	for(int i=1,j=n,last;l<mid||r<mid;){
		if(l<r){
			i++;
			last=l,l+=a[i],l=min(l,mid);
			if(c[i]!=c[j]){
				if(l<r) ans+=l-last;
				else ans+=r-last;
			}
		}else if(l==r){
			i++,j--;
			last=l,l+=a[i],r+=a[j];
			l=min(l,mid),r=min(r,mid);
			if(c[i]!=c[j]){
				if(l<r) ans+=l-last;
				else ans+=r-last;
			}
		}else{
			j--;
			last=r,r+=a[j],r=min(r,mid);
			if(c[i]!=c[j]){
				if(r<l) ans+=r-last;
				else ans+=l-last;
			}	
		}
	}
	cout<<ans;
	return 0;
}

