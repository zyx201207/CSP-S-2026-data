#include<bits/stdc++.h>
using namespace std;

long long m;
long long n,cry[500005],jan[500005];



int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>cry[i];
	

	
	long long final=0;
	for(long long i=1;i<=n;i++){
		long long x=cry[i];
		long long plus=0;
		long long ans=0;	
			
		for(long long j=1;j<=n;j++){
			jan[j]=x-cry[j];
			
			if(jan[j] < 0) jan[j]=m+1;

			plus += jan[j];
			ans++;
				
			if(plus > m){
				ans--;
				plus -= jan[j];
				final=max(final,ans);				
			}
		}
	}
	
	cout<<final;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
