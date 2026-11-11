#include<bits/stdc++.h>
#define fre(name) freopen(name".in","r",stdin),freopen(name".out","w",stdout)
#define int long long
const int N=500005;
using namespace std;
int n,a[N],m,ans;
bool f=1;
signed main(){
	fre("crystal");
//	fre("1");
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	
	
//	#13-15 yinggaihaole
	for(int i=3;i<=n&&f;i++)
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])f=0;
//		cout<<f<<'\n';
	
	if(f){
		for(int i=1;i<=n;i++){
			if((1+i)*i/2>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	
	
//	#1-9 yinggaihaole
	for(int i=1;i<=n;i++){
		int mm=m,cnt=0;
		for(int j=i;j<=n;j++){
			mm-=(a[j]-a[j-1])*(j-i);
			if(mm<0)break;
			cnt++;
//			cout<<mm<<' ';
		}
		ans=max(ans,cnt);
//		cout<<cnt<<'\n';
	}
//	cout<<'\n';
	cout<<ans;
	return 0;
}