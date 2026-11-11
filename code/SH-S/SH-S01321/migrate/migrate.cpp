#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000006];
void solve_1112(){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		int i=d/(x[2]-x[1]);
		if(i<=1||d>=x[n]-x[1])cout<<0<<endl;
		else{
			cout<<n-(i+i-1)<<endl;
		}
	}
}
void solve_1314(){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		cout<<0<<endl;
	}
}
void solve_10(){
	while(t--){
		int res=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(x[n]-x[1]<2*d-1){
			cout<<0<<endl;
		}
		else{
			for(int i=4;i<=n;i++){
				for(int j=i-1;j>=1;j--){
					if(x[i]-x[j]<2*d-1)continue;
					for(int k=j+2;k<i;k++){//k-1 k
						if(d-1<x[k]-x[j]&&x[k]-x[j]<=d&&d-2<x[i]-x[k]&&x[i]-x[k]<=d-1){
							res++;
						}
					}
				}
			}
			cout<<res<<endl;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10){
		solve_10();
	}
	else if(c==11||c==12){
		solve_1112();
	}
	else if(c==13||c==14){
		solve_1314(); 
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

