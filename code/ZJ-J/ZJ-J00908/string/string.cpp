#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200000+10];
char c[200000+10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long b1=1,b2=n,sum1=a[1],sum2=a[n],ans=0;
	while(b1<b2){
		if(c[b1]==c[b2]){
			if(sum1==sum2){
				sum1=sum2=0;
			}else if(sum1>sum2){
				sum1-=sum2;
				sum2=0;
			}else{
				sum2-=sum1;
				sum1=0;
			}
		}else{
			if(sum1==sum2){
				ans+=sum1;
				sum1=sum2=0;
			}else if(sum1>sum2){
				ans+=sum2;
				sum1-=sum2;
				sum2=0;
			}else{
				ans+=sum1;
				sum2-=sum1;
				sum1=0;
			}
		}
		if(sum1==0||sum2==0){
			if(sum1==0){
				b1++;
				sum1=a[b1];
			}
			if(sum2==0){
				b2--;
				sum2=a[b2];
			}
		}
	}
	cout<<ans;
	return 0;
}
