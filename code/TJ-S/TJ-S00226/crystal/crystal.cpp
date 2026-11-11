#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=3;i<=n;i++){
//		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
//			flag=0;
//			break;
//		} 
//	}
 
	sort(a+1,a+n+1);
		ll ix=0;
		for(ll i=1;i<=n;i++){
		    b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
			if(b[i]>m){
				ix=i-1;
				break;
			}
		}
	cout<<ix;
//	}else{
//		b[1]=0;
//		int ans=0;
//		for(int j=1;j<=a[n];j++){
//			int mxt=0;
//			for(int i=2;i<=n;i++){
//				if(a[i]>j){
//					b[i]=b[i-1]+(j-a[i-1])*(i-1);
//					if(b[i]<m) mxt=i-1;
//				break;	
//				}
//			    b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
//				if(b[i]>m){
//					mxt=i-1;
//					break;
//			}
//			}
//			ans=max(ans,mxt);
//			memset(b,0,sizeof b);
//		}cout<<ans<<endl;
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
