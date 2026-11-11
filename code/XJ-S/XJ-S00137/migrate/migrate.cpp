#include<bits/stdc++.h>
using namespace std;
long long a[500001],b[500001],c[500001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		int n,y,s=0;
		cin>>n>>y;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		b[1]=1;
		for(long long i=2;i<=n;i++){
			long long j=i-1;
			while(j>=1&&a[i]-a[j]<=y){
				j--;
			}
			if(j==1){
				b[i]=b[j]+1;
			}
			else{
				b[i]=b[j+1]+1;
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+2;j<=i+3;j++){
				if((a[j]-a[i])>y&&(a[j]-a[i])<2*y&&b[j]>0&&b[i]>0){
					s++;
				}
			}
		} 
		cout<<s<<endl;
		for(long long i=1;i<=n;i++){
			b[i]=0;
		}
	}
	return 0;
} 
