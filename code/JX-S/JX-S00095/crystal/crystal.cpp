#include<bits/stdc++.h>
using namespace std;
long long n,m,a[700005],b[700005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long zd=0;
    if(a[i]-a[n]>a[n]-a[i]){
    	for(long long i=1;i<=n;i++){
	    	b[i]+=a[i]-a[n];
	    	zd+=b[i];
    	}
    }else{
    	for(long long i=1;i<=n;i++){
            b[i]+=a[n]-a[i];
            zd+=b[i];
    	}
    }
    if(zd<=m){
        cout<<n;
        return 0;
    }
    long long js=0;
    sort(b+1,b+n+1);
    int Can_fly=0;
    for(long long i=1;i<=n;i++){
    	b[i]=a[(n+1)/2]-a[i];
    	if(b[i]>=m){
    		Can_fly=i;
    		break;
    	}else{
    		js++;
    	}
    }int zs=0,M=m;
    for(long long i=1;i<=js;i++){
    	m-=b[i];
    	b[i]=0;
    	zs++;
    	if(m<0){
    		cout<<(n+1)/2;
    		return 0;
    	}
    }cout<<zs;
    return 0;
}
