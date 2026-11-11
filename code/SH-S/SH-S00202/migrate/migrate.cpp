#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<4){
			cout<<0<<endl;
			continue;
		} 
		for(long long i=1;i<=n;i++) cin>>a[i];
		long long ans=0;
		for(long long i=1,j=4;i<=n;i++){
			if(j<i+3) j=i+3;
			while(a[j]-a[i]<=d) j++; 
			for(;a[j]-a[i]<2*d && j<=n;j++){
				long long cnt=0,k,sta=-1;
				for(k=i+1;k<j;k++){
					if(a[k]-a[i]<=d && a[j]-a[k]<=d){
						if(sta==-1) sta=k;
						cnt++;
						if(cnt>2) break;
					}
					else if(cnt>0) break;
				}
				if(cnt==2){
					int p=j+1,q=i-1;
					k=p-2,sta=q+2;
					while(p<=n && a[p]-a[p-1]<=d && a[p]-a[k]>d) k=p-1,p++;
					while(q>0 && a[q+1]-a[q]<=d && a[sta]-a[q]>d) sta=q+1,q--;
					ans+=(p-j)*(i-q);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
