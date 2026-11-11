#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ca,a[N],c[N],cnt,ans,mx;
bool tk=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			if(i==2) ca=a[2]-a[1];
			else if(a[i]-a[i-1]!=ca) tk=0;
		}
	}
	if(tk){
		int i=1;
		for(;i<=n&&i*i+i<m/ca*2;i++);
		cout<<i;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cnt=ans=0;
		for(int j=i;j>0;j--){
			cnt+=a[i]-a[j];
			if(cnt<=m) ans++;
			else break;
		}
		mx=max(mx,ans);
	}
	cout<<mx;
	return 0;
}