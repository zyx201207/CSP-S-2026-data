#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long a[2000005];
long long ans=0;
int cc,t;
void ss(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int c=0;
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int c=0;
			for(int k=i;k<=j;k++){
				if(a[k]-a[i]<=d&&a[j]-a[k]<=d){
					c++;
				}
			}
			if(c==2)ans++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cc>>t;
	while(t--){
		ss();
	}
}
