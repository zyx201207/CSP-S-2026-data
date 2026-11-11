#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,answer[100];
	cin>>c>>t;
	for(long long i=0;i<t;i++){
		long long s=0;
		long long n,d;
		cin>>n>>d;
		long long a[n];
		for(long long j=0;j<n;j++){
			cin>>a[j];
		}
		for(long long x=0;x<n-d-1;x++){
			long long s1=0;
			for(long long y=x+d+1;y<n;y++){
				for(long long z=x+1;z<y;z++){
					if(a[z]-a[x]<=d&&a[y]-a[z]<=d)s1++;
				}
				if(s1==2)s++;
			}
			
		}
		answer[i]=s;
	}
	for(long long i=0;i<t;i++)cout<<answer[i]<<endl;
	
	return 0;
}