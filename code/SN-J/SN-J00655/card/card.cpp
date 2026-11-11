//mahaoyu  yuan dong di er zhong xue SN-J00655
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000000],b[1000000],s[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;s[i]=0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<i;j++){
			b[j]=1;
		}
		for(long long j=i;j<=n;j++){
			for(long long k=j-1;k>=i;k--){
				if(b[k]==0){
					if(a[k]==a[j]){
						for(int o=k;o<j;o++){
							b[o]=1;
						}
				   	}
				}
			}
		}
		for(long long j=1;j<=n;j++){
			if(b[j]==0){
				s[a[j]]++;

			}
			else{
				b[j]=0;
			}
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
