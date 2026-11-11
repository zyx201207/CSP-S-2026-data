#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,m;
long long x[2000005],d,y[2000005],a,s;
int main(){
	freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		s=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			scanf("%d",&x[i]);
		for(int i=1;i<n;i++){
			if(x[i+1]-x[i]>d){
				n=i-1;
				break;
			}
		}
		if(c==11||c==12){
			if(x[2]-x[1]<=2*d) cout<<n-3;
			else cout<<0;
			cout<<endl;
			continue;
		}
		for(int i=1;i<=n-3;i++){
			y[i]=1;a=i;
			for(int j=1;j<=n;j++){
				for(int q=i+j;q<=n;q++){
					if(x[q]-x[a]>d){
						a=q-1;
						break;
					}
				}
				for(int q=a-1;q>=i+j;q--){
					for(int p=i+j-1;p<q;p++){
						if(x[q]-x[p]<=d) y[q]+=y[p];
					}
				}
				for(int q=j+i;q<=n;q++) if(y[q]==2) s++;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}