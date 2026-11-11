#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		do{
			int j=(l+r)/2;
			if(j==i){
				break;
			}
            long long p=a[j]*(j-i)-(b[j-1]-b[i-1]);
            if(p==m){
                if(j-i+1>maxx){
                	maxx=j-i+1;
				}
				break;
			}else if(p<m){
                if(j-i+1>maxx){
                	maxx=j-i+1;
				}
				l=j+1;
			}else{
                r=j;
			}
		}while(l<r);
	}
	cout<<maxx;
	return 0;
}