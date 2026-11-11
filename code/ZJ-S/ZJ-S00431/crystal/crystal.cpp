#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],l,ans,mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans+=a[i];
		while((i-l)*a[i]-ans>m){
			l++;
			ans-=a[l];
		}mx=max(mx,i-l);
		
	}cout<<mx;
	return 0;
}
