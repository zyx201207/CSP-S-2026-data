#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N],sum=0,ch=0;
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1;
	for(int i=1;i<=n;i++){
		ch+=(i-l)*(a[i]-a[i-1]);
		
		while(ch>m&&l<n){
			ch-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
