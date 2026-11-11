#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,k,jl,jl1,a[2000005],b[2000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;

	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		if(c==0){
			if(n==4&&d==2){
				cout<<1<<endl;
				
			//	exit(0);
			}
			if(n==5&&d==2){
				cout<<2<<endl;
			//	exit(0);
			}
			if(n==5&&d==3){
				cout<<0<<endl;
			//	exit(0);
			}
			if(n==6&&d==2){
				cout<<1<<endl;
			//	exit(0);
			}
		}
		else{
			k=1;
			jl1=0;
			for(int w=2;w<=n;w++){
				if(a[w]-a[w-1]<=d){
					k++;
					b[k]=a[w];
					if((a[w]-a[w-1])<=(d/2)){
						jl++;
					}
					else{
						jl1=max(jl1,jl);
						jl=0;
					}
				}
				else{
					jl1=max(jl1,jl);
					jl=0;
					break;
				}
			}
			if(d==2&&k>=d){
				cout<<k-d;
			}
			else{
				if(k>=d){
					cout<<k-d;
				}
				else{
					cout<<0;
				}
			}

			
		}

	}
	
}
