 #include<bits/stdc++.h>
 using namespace std;
 #define For(a,b,c) for(int a=b;a<=c;a++)
 #define Rof(a,b,c) for(int a=b;a>=c;a--)
 #define int long long
 
 const int N=5e5+5;
 int a[N],b[N],sum[N];
 
 signed main(){
 	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	For(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	For(i,1,n-1)b[i]=a[i+1]-a[i];
	For(i,1,n-1)sum[i]=sum[i-1]+b[i];
	int l=0,r=n-1;
	while(l<r){
		int mid=(l+r+1)>>1;
//		cout<<"l: "<<l<<"\n";
//		cout<<"r: "<<r<<"\n";
//		cout<<"mid: "<<mid<<"\n";
		int t=0;
		For(i,1,mid)t+=b[i]*i;
//		cout<<t<<' ';
		int mn=t;
		For(i,mid+1,n-1){
			t=t-sum[i-1]+sum[i-mid-1]+b[i]*mid;
//			cout<<t<<' ';
			mn=min(mn,t);
		}
//		cout<<"\nmn: "<<mn<<"\n\n";
		if(mn<=m)l=mid;
		else r=mid-1;
	}
	cout<<l+1<<'\n';
	return 0; 
 }
