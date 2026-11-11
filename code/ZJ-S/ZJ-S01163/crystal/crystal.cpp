#include<bits/stdc++.h>
using namespace std;
long long n,m;
bool t=true;
long long a[1000006]={0},b[1000006]={0},ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)t=false;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	if(m>=a[n]*n||b[n]==a[n]*n){
		cout<<n<<endl;
		return 0;
	}
	if(t==true){
		for(long long i=1;i<=n;i++){
			if(m>=(1+i-1)*(i-1)/2){
				ans=max(ans,i);
			}
		}
		cout<<ans<<endl;
		return 0;
	}else{
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=i;j++){
				if(ans>i-j+1)break;
				if(b[i]-b[j-1]+m>=a[i]*(i-j+1)){
					ans=max(ans,i-j+1);
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
