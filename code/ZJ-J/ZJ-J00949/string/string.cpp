#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct node{
	int len,l,r;
	char c;
}a[N];
long long n,ans,sum,idd;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;idd=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;sum+=a[i].len;
	}
	for(int i=1;i<=n;i++){
		a[i].l=a[i-1].r+1,a[i].r=a[i].l+a[i].len-1;
	}
	for(int i=1;i<=n;i++){
		if(a[i].l>sum/2){break;}
		int idl,idr;
		int L=0,R=n+1,M;
		while(L+1<R){
			M=(L+R)>>1;
			if(a[M].r>=sum-a[i].l+1) R=M;
			else L=M;
		}
		idr=R;
		L=0,R=n+1,M;
		while(L+1<R){
			M=(L+R)>>1;
			if(a[M].r>=sum-a[i].r+1) R=M;
			else L=M;
		}
		idl=R;
		if(idl<=i) idl=i;
		for(int j=idl;j<=idr;j++){
			if(a[j].c!=a[i].c) ans+=(min(a[j].r,sum-a[i].l+1)-max(a[j].l,sum-a[i].r+1)+1);
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
