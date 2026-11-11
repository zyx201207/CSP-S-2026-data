#include<bits/stdc++.h>
using namespace std;
long long c,k,b[100001],a[1000001],ck[100001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>k;
	while(k--){
		long long n,m,u=0,v=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1) {
				b[++u]=a[i]-a[i-1];
			}
		}
		for(int i=1;i<=u;i++){
			if(b[i]&&b[i+1]&&b[i+2]&&b[i]+b[i+1]+b[i+2]>m&&()) v++;
			if(b[i]&&b[i+1]&&b[i+2]&&b[i+3]&&(b[i]+b[i+1]<=m&&b[i+2]+b[i+3]<=m&&((b[i]+b[i+1]+b[i+2]<=m&&b[i+1]+b[i+2]+b[i+3]>m)||(b[i]+b[i+1]+b[i+2]>m&&b[i+1]+b[i+2]+b[i+3]<=m))))v++;
			
		}
		cout<<v<<endl;
	}
	
}
