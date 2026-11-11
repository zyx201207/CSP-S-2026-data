#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
long long a[N],b[N];
long long sum[N];
int main(){
	freopen("migrate2.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(sum,0,sizeof(sum));
		int n;
		long long m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<n;i++){
			b[i]=a[i+1]-a[i];
			sum[i]=sum[i-1]+b[i];
			if(b[i]>m){
				sum[i]=0;
			}
		}
		long long cnt=0;
		for(int i=1;i<n;i++){
			for(int j=i;j<n;j++){
				if(b[j]<=m&&sum[j]-sum[i]+1==2*m-1){
					cnt++;
				}else if(b[j]>m){
					i=j+1;
					break;
				}

			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 


