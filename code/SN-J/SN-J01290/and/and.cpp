#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mx;
int a[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int v=a[1];
		for(int i=2;i<=n;i++){
			v=v&a[i];
		}
		cout<<v;
		return 0;
	}else if(m==1){
		int v=0;
		for(int i=1;i<=n;i++){
			v=max(v,a[i]);
		}
		cout<<v;
	}else if(m==2){
		int v=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				v=max(v,a[i]&a[j]);
			}
		}
		cout<<v;
	}
//cout<<s<<" "<<mv<<"\n";
}
