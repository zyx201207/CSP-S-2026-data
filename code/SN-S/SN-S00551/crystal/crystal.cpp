#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
ll n,a[maxn],m,ma,an=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
		an&=a[i];
	}
		if(m==1){
			cout<<ma;
			return 0;
		}
		if(m==n){
			cout<<an;
			return 0;
		}
		if(m==2){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int p=a[i]&a[j];
					ans=max(ans,p);
				}
			}
			cout<<ans;
			return 0;
		}
} 
