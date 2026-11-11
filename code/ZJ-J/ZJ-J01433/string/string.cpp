#include<bits/stdc++.h>
using namespace std;
long long a[200009];
char b[200009];
long long c[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
		c[i]=sum;
	}
	long long t1=0,t2=0;
	if(sum%2==0){
		t1=sum/2;
		t2=t1+1;
	}else{
		t1=sum/2;
		t2=t1+2;
	}
	c[0]=0;
	int x1=t1,x2=t2;
	for(int i=1;i<=n;i++){
		if(c[i-1]<t1&&t1<=c[i]) t1=i;
		if(c[i-1]<t2&&t2<=c[i]) t2=i;
	}
	long long ans=0;
	long long q=sum;
	for(int i=1,j=n;i<=t1&&j>=t2&&q>=x2;i++){
		if(b[i]==b[j]){
			if(q-(long long)c[j-1]>=(long long)a[i]) q-=(long long)a[i];
			else{
				while(q-(long long)c[j-1]<(long long)a[i]&&q>=x2){
					if(b[j-1]==b[i]){
						q=(long long) c[j-1];
						j--;
					}
					else{
						long long k=(long long)(a[i]-q+c[j-1]);
						if(a[j-1]<k){
							j--;
							ans+=(long long)a[j];
							q=(long long)c[j-1];
						}else{
							j--;
							ans+=k;
							q=(long long)c[j]-k;
						}
					}
				}
			}
		}else{
			if(q-(long long)c[j-1]>=(long long)a[i]){				
				ans+=a[i];
				q-=(long long)a[i];
			}
			else{
				ans+=q-(long long)c[j-1];
				while(q-(long long)c[j-1]<(long long)a[i]&&q>=x2){
					if(b[j-1]==b[i]){
						q=(long long)c[j-1];
						j--;
					}else{
						long long k=(long long)(a[i]-q+c[j-1]);
						if(a[j-1]<k&&q>=x2){
							j--;
							ans+=(long long)a[j];
							q=(long long)c[j-1];
						}else if(q>=x2){
							j--;
							ans+=k;
							q=(long long)c[j]-k;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}