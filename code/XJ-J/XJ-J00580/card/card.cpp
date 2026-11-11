#include <bits/stdc++.h>
using namespace std;
int z[500005];
int z2[500005];
int x[300005];
int y[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a,b=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		z[i]=a;
		z2[i]=a;
	}
	for(int i=1;i<=m;i++){
		x[z[i]]++;
		for(int j=1;i<=m;i++){
			if(x[i]>1){
				y[b]=i;
				b++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b;j++){
			if(z[j]==y[i]){
				mumset(z[j],z[i-1],0);
				y[i]--;
				if(y[i]=1)
				y[i]==0;
			}
		}
		for(int h=1;h<=n;h++){
			if(z[h]==i){
				
			}
		}
		
	}
	cout<<b<<n<<m;
	return 0;
}