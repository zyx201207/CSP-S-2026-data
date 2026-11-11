#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],ans=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
//		cout<<" "<<i<<"\n";
	}
	sort(a+1,a+n+1,cmp);
	
	if (m==1){
		cout<<a[1];
		return 0;
	}
	if (m==n){
		ans=a[1];
		for (int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if (m==2){
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	/*
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			ans=max(ans,ans&)
		}
	} 
	*/
	return 0;
} 





//it's the last time



































































