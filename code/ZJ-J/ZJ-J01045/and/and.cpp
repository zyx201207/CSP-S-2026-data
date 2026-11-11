#include <iostream>
#define max(a,b) (a>b?a:b)
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=0,ans=0;
	cin >> n >> m;
	int a[100005]={};
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i==1)ans=a[i];
		ans=(ans&a[i]);
		mx=max(mx,a[i]);
	}if(m==1){
		cout << mx;
	}else if(m==n){
		cout << ans;
	}else if(m==2){
		ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}cout << ans;
	}else if(m==n-1){
		mx=-1;
		for(int i=1;i<=n;i++){
			mx=max(mx,(ans&a[i]));
		}cout << mx;
	}else cout << mx;
	return 0;
}
