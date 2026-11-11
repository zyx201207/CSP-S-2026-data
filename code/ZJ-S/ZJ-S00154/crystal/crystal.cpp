#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500100];
int p[500100];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		p[i]=a[i]-a[i-1];
	int ans=1;
	int l=1,r=1,sum=0;
	while(l<=r&&l<=n&&r<=n){
		if(r==n)	break;
		if(sum+(r-l+1)*p[r+1]<=m)
			sum+=(r-l+1)*p[r+1],r++;
		else
			if(p[r+1]>m)
				l=++r,sum=0;
			else{
				while(l<=r&&sum+(r-l+1)*p[r+1]>m)
					sum-=a[r]-a[l],l++;
				sum+=(r-l+1)*p[r+1],r++;
			}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}//Baixie 0513DTY
//Crystal? Xterfusion!
//X X XXX
//100pts. at 15:02
