//十年OI一场空，不开long long见祖宗
//多测不清空，爆零两行泪
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c<=10){
			ll ans=0;
			for(int i=1;i<=n;i++){
				ll lst=a[i],f=0;
				for(int j=i;j<=n;j++){
					if(a[j]-a[j-1]>d)break;
					if(j>=i+3){
						if(a[j-1]-a[j-3]<=d&&a[j]-a[j-2]<=d&&a[j]-a[j-3]>d){
							if(f==0)f=1;
							else break;
						}
					}
					if(a[j]<=lst+d&&a[j+1]>lst+d)lst=a[j];
					if(f==1)ans++;
				}
			}
			cout<<ans<<endl;	
		}
		else{
			if(n==1||d<(a[2]-a[1])*2)cout<<0<<endl;
			else{
				ll kkksc03_is_gay=d/(a[2]-a[1]);
				cout<<n-kkksc03_is_gay-1<<endl;
			}
		}
	}
	return 0;
}
/*
本！太难了！出题人是gay！！！
*/