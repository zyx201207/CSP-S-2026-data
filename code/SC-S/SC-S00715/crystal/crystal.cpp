#include <bits/stdc++.h>
using namespace std;
const int ma=5*10e5; 
long long n,a[ma],m,maxx=0,minn=1e18,s=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	scanf("%ld%ld",&n,&m);
cin>>n>>m;
	for(int i=0;i<n;i++){
//		scanf("%ld",&a[i]); 
cin>>a[i];
		maxx=max(a[i],maxx);
		minn=min(a[i],minn);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		s+=maxx-a[i];
	}
	if(s<=m){
		cout<<n;
	}else{
		int ans=0;
		for(long long i=minn;i<=maxx;i++){
			long long nnm=m;
			int d=0;
			for(int j=0;j<n;j++){
				if(a[j]<=i){
					nnm-=i-a[j];
					d++;
				}
			}
			if(nnm<0){
				break;
			}
//				cout<<i<<' '<<d<<'\n';
				ans=max(ans,d);
			}
		cout<<ans;
	}
	return 0;
}