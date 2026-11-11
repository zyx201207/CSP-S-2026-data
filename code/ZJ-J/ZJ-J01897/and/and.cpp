#include <bits/stdc++.h>
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("O4")
#pragma GCC optimize("O5")
#pragma GCC optimize("Os")
#pragma GCC optimize("Og")
#pragma GCC optimize("Ofast")
#pragma G++ optimize("O1")
#pragma G++ optimize("O2")
#pragma G++ optimize("O3")
#pragma G++ optimize("O4")
#pragma G++ optimize("O5")
#pragma G++ optimize("Os")
#pragma G++ optimize("Og")
#pragma G++ optimize("Ofast")
#define int long long
using namespace std;
int n,m,i,j,ans,ma,bao,fl,s1,s2,s3,s0,a[200010],f[200010];
bool cmp(int q,int h){
	if(q>h) return 1;
	return 0;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4) fl=1;
	}
	sort(a+1,a+1+n,cmp);
	if(m==n-1){
		ans=a[1];
		for(i=2;i<=m;i++) ans&=a[i];
		cout<<ans;exit(0);
	}
	if(m==2){
		for(i=1;i<=min(n,5000ll);i++)
			for(j=1;j<=min(n,5000ll);j++)
				if(i!=j) ans=max(ans,a[i]&a[j]);
		cout<<ans;exit(0);
	}
	if(!fl){
		for(i=1;i<=n;i++)
			if(a[i]==3) s3++;
			else if(a[i]==2) s2++;
			else if(a[i]==1) s1++;
			else s0++;
		if(s3>=m) cout<<3;
		else if(s3+s2>=m) cout<<2;
		else if(s3+s2+s1>=m) cout<<1;
		else cout<<0;
		exit(0);
	}
	ans=a[1];f[1]=1;
	for(j=1;j<m;j++){
		ma=0;
		for(i=1;i<=n;i++)
			if(!f[i]&&(ans&a[i])>=ma) ma=(ans&a[i]),bao=i;
		f[bao]=1;ans=ma;
	}
	cout<<ans;
	return 0;
}
