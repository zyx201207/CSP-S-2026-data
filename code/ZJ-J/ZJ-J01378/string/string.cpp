#include <bits/stdc++.h>
using namespace std;
long long x,temp1,temp2,n,sum,ans,m,a[200005];
string b,c,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	x=temp2=temp1=sum/2;
	long long i=1;
	m=1;
	while(temp1>0){
		if(temp1>a[i]){
			temp1-=a[i];
			for(long long j=1;j<=a[i];j++,m++){
				c[m]=b[i];
			}
		}else{
			for(long long j=1;j<=temp1;j++,m++){
				c[m]=b[i];
			}
			temp1=0;
		}
		i+=1;
	}
	i=n,m=1;
	while(temp2>0){
		if(temp2>a[i]){
			temp2-=a[i];
			for(long long j=1;j<=a[i];j++,m++){
				d[m]=b[i];
				
			}
		}else{
			for(long long j=1;j<=temp2;j++,m++){
				d[m]=b[i];
			}
			temp2=0;
		}
		i-=1;
	}
	for(int i=1;i<=x;i++){
		if(c[i]!=d[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
