#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,T,n;
ll d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int ans=0;
		ll ch=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) ch=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				int flag=0,pre=-1;
				ll sum=0;
				for(int k=i+1;k<=j;k++){
					if(a[k]-a[k-1]>d){
						flag=-1;
						break;
					}
					if(sum+a[k]-a[k-1]>d){
						if(pre!=-1){
							if(sum+a[pre]-a[pre-1]<=d) flag++;
							if(pre>=i+2&&sum+a[pre]-a[pre-2]<=d){
								flag++;
								break;
							}
						}
						pre=k-1,sum=a[k]-a[k-1];
					}else{
						sum+=a[k]-a[k-1];
					}
					if(flag>1) break;
				}
				if(pre!=-1){
					if(sum+a[pre]-a[pre-1]<=d) flag++;
					if(pre>=i+2&&sum+a[pre]-a[pre-2]<=d){
						flag++;
					}
				}
				if(flag==1){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/