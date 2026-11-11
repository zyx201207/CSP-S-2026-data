#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N=5e5+7;
long long a[N];
long long ans=-1;
long long pre[N];
bool check(int x,int pos){
	int l=pos-x;
	if(1ll*(long long)(pre[pos]-pre[l]+m)>=1ll*(long long)(a[pos]*x)){
		return true;
	}
	else return false;	
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		cout<<a[i]<<" ";
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
//		if(1ll*(pre[i]+m)-a[i]*i*1ll>=0){
//			ans=max(ans,1ll*i);
//		}
//		else{
//			break;
//		}
//		cout<<pre[i]<<" ";
	}
//	cout<<'\n';
	for(int i=n;i>=1;i--){
		if(1ll*(pre[i]+m)-a[i]*i*1ll>=0){
//			cout<<"ans"<<i<<" "<<ans<<'\n';
//			if(ans<i){
//				cout<<"case1"<<'\n';
//			}
			ans=max(ans,1ll*i);
			break;
		}
		else{
			long long tmp=0;
			int l=1,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(!check(mid,i)){
					r=mid-1;
					tmp=mid;
				}
				else l=mid+1;
			}
			ans=max(ans,r*1ll);
		}
	}
	cout<<ans;
//	for(int i=n;i>=1;i--){
		
//	}
//	long long l=1,r=n;

//	
//	
//	
	
	
	
	
	return 0;
}
