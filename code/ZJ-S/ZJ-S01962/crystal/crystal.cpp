#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pb push_back
#define burn while
using namespace std;
const int N=5e5+10;
const bool ckr=0;

int n,ans;
ll m,a[N],s[N];

void solve(){
	n=ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(ckr)cout<<"end input."<<endl;
	if(n==1){
		cout<<1<<endl;
		return ;
	}
	if(n==2){
		if(a[2]-a[1]<=m)cout<<2<<endl;
		else cout<<1<<endl;
	}
	if(ckr)cout<<"Here ,Before sort!"<<endl;
	sort(a+1,a+1+n);
	if(ckr)cout<<"After sort!And going to mix 2Na,H2O and -a2 to make N2O and H2! "<<endl;
	int l=1,r=2;
	ll usedN2O=(r-l)*(a[r]-a[r-1]);
	burn(l<=r){
		if(ckr)cout<<"l,r="<<l<<" , "<<r<<endl;
		if(usedN2O<=m){
			ans=max(ans,r-l+1);
			r++;
			if(r>n)break;
			usedN2O+=(r-l)*(a[r]-a[r-1]);
		}else{
			usedN2O-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans<<endl;
	return ;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	solve();

	return 0;
}

