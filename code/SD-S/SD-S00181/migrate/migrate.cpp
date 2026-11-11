#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int a[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,sum=0,flag=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if((n-1)%d==0 || n<=d){
			sum=0;
		} else if(a[3]-a[1]<=d){
			if(n%2==0){
				for(int i=1;i<=n-3;i+=2){
					if(d>i){
						sum+=i;
					}
				}
			} else{
				for(int i=2;i<=n-3;i+=2){
					if(d>=i){
						sum+=i;
					}
				}
			}
		}
		cout<<sum<<endl;
		memset(a,0,sizeof(a));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
