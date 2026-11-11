#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int a[N],sum,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	sum=max(sum,a[i]);
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	if(m==1){
		cout<<sum;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			int x=a[i]&a[i+1];
			ans=max(ans,x);
		}
		cout<<ans; 
	}
	return 0;
}

