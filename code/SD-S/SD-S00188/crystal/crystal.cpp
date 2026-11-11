#ifdef icop
#define nofl
#endif
#ifdef allallallall
//jimmy
//long long,momery,file,flush
#endif
#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5;
int a[N+5];
int q[N*2+5],l,r;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	#ifndef nofl
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=1,r=0;
	int ans=0;
	int cnt=0;
	long long sum=0;
	while(r<=n){
		int u=q[r];
		r++;
		q[r]=a[r];
		int c=abs(a[r]-u);
		sum+=cnt*c;
		cnt++;
//		cout<<l<<" "<<r<<" "<<cnt<<" "<<sum<<" "<<ans<<"\n";
		while(sum>m){
			int c=abs(a[r]-q[l]);
			l++;
			sum-=c;
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
}
