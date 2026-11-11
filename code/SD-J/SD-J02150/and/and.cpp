#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],maxx,ans,sum;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=ans&a[i];
		maxx=max(maxx,a[i]);
	}
    if(m==1){
    	cout<<maxx;
	}else if(m==n){
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum;
	}
	return 0;
}
