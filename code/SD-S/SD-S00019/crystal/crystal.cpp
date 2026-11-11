//Accept at 14:50
#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const int N=5e5+10;
/*====================*/
ll n,m;
ll a[N],maxx,s[N];
/*====================*/
void Solve(void){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ll num=0,l=1,r=i;
		while(l<r){
			ll mid=(l+r+1)/2;
			if(a[i]*mid-(s[i]-s[i-mid])<=m){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		maxx=max(maxx,l);
		//cout<<maxx<<"\n";
	}
	cout<<maxx;
}
/*====================*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll T=1;//cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}
//@Leaf_c17
//Pqh123_AUG
//1236stdc
//ww3733a
//Beauty_Maths_Withoi
//FlashBadge
//couil
//GHJ2023
//unhappypig
