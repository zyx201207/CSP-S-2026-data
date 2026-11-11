#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n;
    long long a[500000]={0};
    unsigned long long m;
long long fr(long long a[],unsigned long long m,long long i){
	if(i==n){
		return 1;
	}
	long long ans=1;
	unsigned long long x=m;
	long long j=i;
	while(x>=((a[j+1]-a[j])*ans)&&j<n-1){
		
		x=x-((a[1+j]-a[j])*ans);
		ans++;
		j++;
		
	}
	//cout<<endl;
	return max(ans,fr(a,m,i+1));
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
    	scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	
	printf("%lld",fr(a,m,0));
	fclose(stdin);
	fclose(stdout);
    return 0;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
//cout<<" 	 "<<ans<<"  "<<x<<endl;
//cout<<j<<"		"<<ans<<"  "<<x<<" -("<<a[j+1]<<" - "<<a[j]<<")*"<<ans<<endl;
