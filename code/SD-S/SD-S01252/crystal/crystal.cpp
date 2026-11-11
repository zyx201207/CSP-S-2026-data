//Oct31==Dec25?
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],b[N],ans,tot,cnt; 
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int l=1;
	for(int r=1;r<=n;r++){
		tot=b[r]-b[l-1];
		cnt=a[r]*(r-l+1)-tot;
		while(cnt>m){
			l++;
			tot=b[r]-b[l-1];
			cnt=a[r]*(r-l+1)-tot;
		}
		ans=max(ans,r-l+1);
//		cout<<l<<" "<<r<<" "<<tot<<" "<<cnt<<"\n";
	}
	cout<<ans<<'\n';
	
	return 0;
}
