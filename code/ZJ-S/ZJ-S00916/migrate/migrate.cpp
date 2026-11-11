#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,f[100005],a[2000006],x,y;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int b=1;b<=n;b++){
			for(int e=b+3;e<=n;e+=2){
				x=e-b;
				x=x/2;
				if(d<(a[e]-a[b]) && (a[e]-a[b])<=2*d){
					if((a[e]-a[b+x])<=d){
						if((a[e-x]-a[b])<=d){
							f[i]++;
						}
					}
				}
				else{
					break;
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<f[i]<<endl;
	}
}
