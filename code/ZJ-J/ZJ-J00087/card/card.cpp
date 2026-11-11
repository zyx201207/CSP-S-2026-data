#include<bits/stdc++.h>
using namespace std;
long long n,m,l=0;
long long a[500001],b[500001]={0},s[300001]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long v=1;v<=n;v++){
		for(long long i=v;i<=n;i++){
			b[i]=a[i];
		}
		l=n-v+1;
		for(long long i=v;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(b[i]==b[j]){
					l-=j-i;
					for(long long k=i;k<=l;k++){
						b[k]=b[k+j-i];
					}
				}
			}
		}
		for(long long j=1;j<=l;j++){
			s[b[j]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}