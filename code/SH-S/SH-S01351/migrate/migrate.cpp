#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],zh[2000005],ansn=0,naa,ans[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ansn=0;
		cin>>n>>d;
		cin>>a[1];
		naa=a[1];
		zh[1]=1;
		for(int i=2;i<=n;i++){
			cin>>a[i];
			if(naa+d>=a[i])zh[i]=zh[i-1];
			else if(a[i-1]+d<a[i]){
				n=i-1;
				break;
			}
			else{
				zh[i]=zh[i-1]+1;
				naa=a[i];
			}
		}

		zh[1]=0;
		ans[1]=1;
		for(int i=2;i<=n;i++){
			int q=i;

			while(q>=1&&zh[q]>=zh[i]-1){
				if(zh[q]>zh[i]-1){
					q--;
					continue;
				}
				else ans[i]+=ans[q];
				q--;
			}
			if(ans[i]==2){
				ansn++;
			}
		}
		cout<<ansn<<"\n";
	}
	
	return 0;
}
