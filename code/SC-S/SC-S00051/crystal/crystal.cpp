#include<bits/stdc++.h>
#define int long long
#define cin std::cin
#define cout std::cout
#define endl '\n'
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],sum[maxn],c[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	c[1]=1;
	for(int i=2;i<=n;i++) c[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+c[i];
//	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
//	cout<<endl<<endl<<endl<<endl<<endl;
//	for(int i=1;i<=n;i++) cout<<sum[i]<<" ";
//	cout<<endl<<endl<<endl<<endl<<endl;
	int l=1,r=2,num=0,maxx=1;
	bool flag=1;
	while(l<=n && r<=n){
		int len=r-l+1;
		if(len==0){r++; num=0; continue;}
		if(flag) num+=(len-1)*c[r]; // add a[r]
		flag=0;
//		if(num>=1e18){flag=1; break;}
//		cout<<num<<endl;
		if(num<=m && len>=maxx) maxx=len,r++,flag=1;
		else if(num<=m) r++,flag=1;
		else num-=sum[r]-sum[l],l++;
		
	}
//	if(flag) cout<<"越界"<<endl;
	cout<<maxx<<endl;
	return 0;
}