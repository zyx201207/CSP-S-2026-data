#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[510000],s[510000];
bool check(int l,int r){
	if(l==r) return 1;
	if(m+s[r]-s[l-1]>=(r-l+1)*a[r]) return 1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=1,maxn=0;
	while(r<=n&&l<=n){
		if(check(l,r)){
			maxn=max(r-l+1,maxn);
			r++;
		}
		else{
			l++;
		}
	}
	cout<<maxn<<"\n";
	////////   ////////        |             |
	//    //   //   //         |             |
	//  //     // //      =====+=====   =====+=====    
	/////      ///             |             |
	//  //     //              |             |
	//    //   //              |             |
	return 0;
}