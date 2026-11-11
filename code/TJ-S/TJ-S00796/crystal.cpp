#include<bits/stdc++.h>
using namespace std;
const int N=500005;

long long n,m,ans=0;
long long a[N],b[N],sum[N];
bool isA=1; 
bool isB=1; 

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    cin>>a[1]>>a[2]; 
    int d=a[2]-a[1];
    for(int i=3;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) isA=0;
        if(a[i]-a[i-1]!=d) isB=0;
    }
    if(!isA && !isB){
    	sort(a+1,a+1+n);
    	for(int i=2;i<=n;i++){
    		b[i]=a[i]-a[i-1];
    		sum[i]=b[i]+sum[i-1];
		} 
		
		long long lm=m;
    	for(int i=2;i<=n;i++){		
    	    long long s=1,j=i-1;
    	    while(j>=1 && m>=(sum[i]-sum[j])){
    	        m-=(sum[i]-sum[j]);
    	        s++;
    	        j--;
    	    }
    	    ans=max(ans,s);
    	    m=lm;
    	}
    	cout<<ans;
	}else if(isA){
//		cout<<"A"<<endl;
		int cnt=1;
		ans=1;
		while(m>0){
			m-=cnt;
			cnt++;
			ans++;
		}
		cout<<ans;
	}else{
//		cout<<"B"<<endl;
		int cnt=abs(d);
		sort(a+1,a+1+n);
		ans=1;
		while(m>0){
			m-=cnt;
			cnt+=abs(d);
			ans++;
		}
		cout<<ans;	
	}
    return 0;
}
