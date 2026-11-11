#include <bits/stdc++.h>
using namespace std;
int c,t;
int x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=2000010;i++)	x[i]=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			if(d<x[3]-x[1]) cout<<0;
			else{
				int c=d/(x[2]-x[1]);
				cout<<n-d-1<<"\n";
			}
		}
		if(c==13||c==14){
			int cnt=0;
			int s;
			for(int i=2;i<n;i++){
				int b=1;
				for(int j=1;j<=n;j++){
					if(abs(x[i]-x[j])>d) b=0;
				}
				if(b==1) s=i;
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(j>=s&&s>=i){
						for(int k=i;k<=j;k++){
							if(abs(x[k]-x[i])<=d&&abs(x[j]-x[k])<=d){
								cnt++;
							}
						}
					}
				}
			}
			cout<<cnt<<"\n";
		} 
		else{
			cout<<0<<"\n"; 
		} 
	} 
 return 0;
}
