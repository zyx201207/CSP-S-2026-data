#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,ans=-1,a[N],s,l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	l=1;
	for(int i=1;i<=n;i++){
		s+=a[i];
		while(a[i]*(i-l+1)-s>m){
			s-=a[l];
			l++;
		}
		ans=max(i-l+1,ans);
	}
	cout<<ans;
	return 0;
}
