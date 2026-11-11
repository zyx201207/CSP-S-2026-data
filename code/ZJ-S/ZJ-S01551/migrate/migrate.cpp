#include<bits/stdc++.h>
using namespace std;
    long long c,t,n,d,x[2000006],len,dat,ans;
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
    	scanf("%lld%lld",&n,&d);
    	for(int i=1;i<=n;i++){
    		scanf("%lld",&x[i]);
		}
		dat=x[2]-x[1];
		bool flag=1;
		for(int i=3;i<=n;i++){
			if(x[i]-dat!=x[i-1]){
				flag=0;
			}
		}
		if(flag==1){
			ans=0;
			d=d/dat*dat;
			len=x[n]-x[1];
			if(d<2*dat){
				cout<<0<<endl;
				continue;
			}
            cout<<(((len-(d+dat))/dat+1)+((len-(2*d-dat))/dat+1))*(d/dat-1)/2;
            return 0;
		}
		len=x[n]-x[1];ans=0;
		if(d>(len+1)/2){
			for(int i=1;i<=n-3+1;i++){
				if(x[i+2]-x[i]>(len+1)/2){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
}
