#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],ans,last;
bool f[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
//	for(int i=1;i<=n;i++){
//		int ma=a[i];
//		int last=0,last1=0;
//		memset(f,0,sizeof f);
//		for(int x=1;x<m;x++){
//			for(int j=1;j<=n;j++){
//				if((last1&a[j])>=ma){
//					ma=(last1&a[j]);
//					last1=a[j];
//					f[last]=0;
//					f[j]=1;
//					last=j;
//				}
//			}
//		}
//		
//		ans=max(ans,ma);
//	}
	if(n==m){
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
	}else if(m==n-1){
		int ma=LLONG_MAX;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ma&=a[j];
				}
			}
			ans=max(ans,ma);
		}
	}else{
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	
	cout<<ans;
	return 0;
} 
