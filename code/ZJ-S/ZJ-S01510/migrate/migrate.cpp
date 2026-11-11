#include<bits/stdc++.h>
#define N 2000050
#define ll long long
using namespace std;
int c,t;
int n;
ll d,a[N],f[N];
int main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		int j=2;
		for(int i=1;i<=n;i++){
			while(a[i]+d>=a[j] && j<=n) j++;
			if(j-i==3 && a[i]+d<a[j]){
				int k=j;
				while(a[i+1]+d>=a[k]){
					k++;
					ans++;
				}
			} 
		}
		cout<<ans<<endl;
		
	}
}
