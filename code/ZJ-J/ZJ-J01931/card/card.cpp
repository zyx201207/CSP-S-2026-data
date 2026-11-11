#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[400005],s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		long long t=0;
		for(long long j=i;j<=n;j++){
			long long f=0;
			for(long long k=1;k<=t;k++){
				if(b[k]==a[j]){
					f=1;
					t=k;
					break;
				}
			}
			if(f==0){
				t++;
				b[t]=a[j];
			}
		}
		for(long long j=1;j<=t;j++){
			s[b[j]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}