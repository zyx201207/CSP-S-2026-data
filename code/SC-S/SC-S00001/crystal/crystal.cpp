#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FILE "crystal"
#define JUDGE
const int N=5e5+5;
int a[N],n,m,qz[N];
bool check(int k){
	for(int i=k; i<=n; i++){
		if(qz[i]-qz[i-k+1]-(a[i]-a[i-k+1])*(i-k)<=m)
			return 1;
	}
	return 0;
}
signed main(){
	#ifdef JUDGE
	freopen(FILE ".in","r",stdin);
	freopen(FILE ".out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++){
		qz[i]=qz[i-1]+(a[i]-a[i-1])*(i-1);
	}
//	for(int i=1; i<=n; i++){
//		cout<<qz[i]<<' ';
//	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid;
//		cout<<l<<' '<<r<<'\n';
	}
	cout<<l-1;
	#ifdef JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}
/*
AC
in 15:14
Yessssssssssssssssssssssssssssssssssssssssss
听说00001容易上奇葩大赏，快把我弄上去

luogu:lmh120802，求关注QAQ 
*/