#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],b[N];
long long m,sum;
int n,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	bool x=true;
	for(int i=1;i<n;i++){
		if(b[i]!=b[i+1]){
			x=false;
			break;
		}
	}
	if(x==true){
		for(int i=1;i<=n;i++){
			if((a[i]+a[1])*i/2-a[1]*i>m){
				cout<<i-1;
				break;
			}
		}
		return 0; 
	}
	for(int j=1;j<n;j++){
		sum=0;
		for(int i=j;i<n;i++){
			sum+=b[i]*(i-j+1);
			if(sum>m){
				ans=max(ans,i-j+1);
				break;
			}
		}
	}
	cout<<ans;
	return 0; 
}
