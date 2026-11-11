#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N];
bool A=1;
bool B=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int g=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)A=0;
	}
	sort(a+1,a+n+1);
	g=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=g){
			B=0;
			break;
		}
	}
	if(A){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=i;
			if(m<ans){
				cout<<i<<endl;
				return 0;
			}
		}
		cout<<n<<endl;
		return 0;
	}else if(B){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=i*g;
			if(m<ans){
				cout<<i<<endl;
				return 0;
			}
		}
		cout<<n<<endl;
		return 0;
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			int z=a[i],sum=0;
			for(int j=i;j<=n;j++){
				sum+=(j-i)*(a[j]-z);
				z=a[j];
				//cout<<sum<<endl;
				if(sum>m){
					ans=max(ans,j-i);
					//cout<<"!"<<ans<<endl;
					break;
				}
			}
			if(ans==n){
				cout<<ans<<endl;
				return 0;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
}
