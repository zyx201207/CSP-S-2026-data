#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
long long a[N],b[N];
long long sum[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
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
				if(b[j]<=m){
					for(int k=1;k*m<sum[j];k++){
						if(m*k-1==sum[j]-sum[i]+1){
							cnt++;
							break;
						}
					}
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




//0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6

