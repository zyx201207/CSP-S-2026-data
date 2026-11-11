#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],c[500050],ans,lst_a,lst_c;
bool ff=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(lst_a!=a[i]) c[i]=1ll*(i-1)*(a[i]-a[i-1])+c[i-1];
		else c[i]=lst_c;
		if(c[i]>m){
			ans=i-1;
			ff=1;
			break;
		}
		lst_a=a[i],lst_c=c[i];
	}
	if(ff) cout<<ans;
	else cout<<n;
	return 0;
}
