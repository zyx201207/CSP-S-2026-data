#include<bits/stdc++.h>
using namespace std;
long long a[2000005],mi,d;
int c,t,n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d>>a[1];
		mi=LLONG_MAX;
		for(int j=2;j<=n;j++){
			scanf("%lld",&a[j]);
			mi=min(mi,a[j]-a[j-1]);
		}
		if(mi>d) cout<<"0\n";
		else{
			if(c==0||c==12){
				if(2*mi>d||d/mi*2>n) printf("0\n");
				else printf("%lld\n",n-d/mi*2+1);
			}else{
				long long x=0;
				for(int j=1;j<=n;j++){
					for(int k=j+3;k<=n;k+=2){
						if(a[(j+k+1)/2]-a[j]<=d&&a[k]-a[(j+k+1)/2]<=d&&a[(j+k+1)/2+1]-a[j]>d&&a[k]-a[(j+k+1)/2-1]<=d&&a[k]-a[(j+k+1)/2-2]>d) x++;
					}
				}
				printf("%lld\n",x);
			}
		}
	}
	return 0;
}
