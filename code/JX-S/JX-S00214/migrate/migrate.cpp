#include<bits/stdc++.h>
using namespace std;
bool f=1;
int c,t;
int n;
long long d,gc;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		f=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(f){
				if(i==2) gc=a[i]-a[i-1];
				if(i>2){
					if(a[i]-a[i-1]!=gc) f=0;
				}
			}
		}
		if(f){
			int s=d/gc;
			if(s<=1){
				cout<<0;
				continue;
			}
			int ans=0;
			ans+=(s+s+2);
			ans+=((n-s-s-2)*2);
			cout<<ans<<endl;
		}
		else{
			cout<<n*n-d*n<<endl;
		}
	}
	return 0;
}
