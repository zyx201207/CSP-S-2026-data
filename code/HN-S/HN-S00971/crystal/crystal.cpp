#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+5;
const ll M=1e12;
int n,ans,res;
ll sum,a[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	res=1,ans=1;
	int l=1;
	for(int i=2;i<=n;i++){
		if(sum+res*(a[i]-a[i-1])>m){
			sum+=res*(a[i]-a[i-1]); res++;
			while(sum>m) {
			    sum-=(a[i]-a[l]),l++,res--;
		    }
			ans=max(ans,res);
		}
		else{
			sum+=res*(a[i]-a[i-1]); res++;
			ans=max(ans,res);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
