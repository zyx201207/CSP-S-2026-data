#include<bits/stdc++.h>
#define int long long
#define fir first
#define sec second
#define mkp make_pair
const int N=5e5+10;
using namespace std;
int n,m;
int a[N];
int b[N];
int sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	for(int i=1;i<=n-1;i++) sum[i]=sum[i-1]+b[i];
	int all=0,len=0;
	int l=0,r=0;
	bool flag=true;
	while(r<n){
		while(all<=m&&r<n) {
			r++;flag=true;
			all+=(r-l+1)*b[r];
		}
		len=max(len,r-l);
		while(all>m&&l<=r) {
			all-=sum[r]-sum[l];
			l++;
		}
		if(l==r+1) r=l;
	}
	cout<<len+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//5 5
//1 2 4 8 9

//5 8
//-3 -1 2 2 7

//Oct31==Dec25?
