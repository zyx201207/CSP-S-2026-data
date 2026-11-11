#include<bits/stdc++.h>
using namespace std;
const long long N=500010,M=300010;
long long a[N],s[M],q[N],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	long long n,m;cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(long long z=1;z<=n;z++){
		long long len=0;
		for(long long i=z;i<=n;i++){
			bool ok=false;
			for(long long j=1;j<=len;j++){
				if(q[j]==a[i]){
					ok=true;
					t=j;
					break;
				}
			}
			if(ok){
				len=t;
				q[len]=a[i];
			}
			else q[++len]=a[i];
		}
		for(long long k=1;k<=len;k++){
			s[q[k]]++;
		}
	} 
	for(long long i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
} 
