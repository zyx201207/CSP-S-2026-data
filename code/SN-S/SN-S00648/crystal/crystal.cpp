#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[50005],b[50005];
bool fl;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	long long cha=0;
	fl=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cha=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cha){
			fl=1;
			break;
		}
	}
	if(!fl){
		for(int i=n;i>=2;i--){
			if(m>(a[1]+a[i-1])*(i-1)/2){
				cout<<i<<endl;
				return 0;
			}
		}
		cout<<1<<endl;
		return 0;
	}else{
		b[0]=0;
		b[1]=a[1];
		for(int i=2;i<=n;i++){
			b[i]=b[i-1]+a[i];
		}
		int ans=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<n;j++){
				if(i+j>n){
					continue;
				}
				if(b[i+j]-b[i-1]+m>a[i+j]*(j+1)){
					ans=max(ans,j+1);
				}else if(b[i+j]-b[i-1]+m==a[i+j]*(j+1)){
					ans=max(ans,j+1);
				}else if(b[i+j]-b[i-1]+m<a[i+j]*j){
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
