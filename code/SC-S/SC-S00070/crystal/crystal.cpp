#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],d[500005],cnt,b[500005],s[500005],ans,num;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])b[++cnt]=a[i];
		d[i]=cnt;
		s[cnt]++;
	}
	int l=1,q=0;
	for(int r=1;r<=cnt;r++){
		num+=q*(b[r]-b[r-1]);
		while(l<r&&num>m){
			q-=s[l];
			num-=s[l]*(b[r]-b[l]);
			l++;
		}
		int res=0;
		if(l!=1)res=min(s[l-1],(m-num)/(b[r]-b[l-1]));
		ans=max(ans,res+q+s[r]);
		q+=s[r];
	}
	cout<<ans;
	return 0;
}