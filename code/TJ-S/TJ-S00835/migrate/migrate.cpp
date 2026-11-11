#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	long long final[t];
	for(long long e=0;e<t;e++){
		long long n,d,ans=0;
		cin>>n>>d;
		long long l[n];
		for(long long i=0;i<n;i++){
			cin>>l[i];
		}
		for(long long i=0;i<n;i++){
			for(long long j=i+2;j<n;j++){
				if(l[j]-l[i]<=d){
					continue;
				}
				else{
					long long sum=0;
					for(long long k=0;k<n;k++){
						if(max(l[i],l[k])-min(l[i],l[k])<=d&&max(l[j],l[k])-min(l[j],l[k])<=d){
							sum++;
						}
					}
					if(sum==2){
						ans++;	
					}
				}
		    }
		}
		final[e]=ans;
	}
	for(int i=0;i<t;i++){
		cout<<final[i]<<endl;
	}
	return 0;
}

