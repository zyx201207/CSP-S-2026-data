#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
int n;
ll m,a[N],mmax;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=1,num=0;
	while(l<=n&&r<=n){
		if(num<=m){
			mmax=max(mmax,r-l+1);
			if(r<n){
				num+=1ll*(a[r+1]-a[r])*(r-l+1);
				r++;
			}else{
				num-=1ll*(a[r]-a[l]);
				l++;
			}
		}else{
			num-=1ll*(a[r]-a[l]);
			l++;
		}
	}
	cout<<mmax<<endl;
}
