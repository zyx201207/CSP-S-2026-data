#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,sum,xy;
int main(){
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n/2+1];
	bool x=0;
	for(int i=1;i<=n;i++){
		if(a[i]==ans){
			if(!x){
				xy=i-1;
				x=1;
			}
			sum++;
		}
	}
	for(int i=xy;i>=1;i--){
		m=m-ans+a[i];
		a[i]=ans;
		sum++;
		if(m<0){
			sum--;
			break;
		}else if(m==0){
			break;
		}
	}
	cout<<sum;
	return 0;
}