#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1,l=1;
	for(int r=2;r<=n;r++){
		if(a[r]==a[r-1]){
			ans=max(ans,r-l+1);
			continue;
		}
//		cout<<r<<" "<<m<<" "<<(a[r]-a[r-1])*(r-1)<<'\n';
		while(l<r&&m<(a[r]-a[r-1])*(r-l)){
			m+=a[r-1]-a[l];
			l++;
		}
		if(m>=(a[r]-a[r-1])*(r-l)){
			m-=(a[r]-a[r-1])*(r-l);
			ans=max(ans,r-l+1);
		}
		else	break;
	}
	cout<<ans;
	return 0;
}