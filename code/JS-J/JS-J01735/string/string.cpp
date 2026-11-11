#include<bits/stdc++.h>
using namespace std;
long long n,ans,num,sum,x;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum>num/2){
			for(int j=n+1;j>i+1;j--){
				a[j]=a[j-1];
				c[j]=c[j-1];
			}
			a[i+1]=sum-(num+1)/2;
			c[i+1]=c[i];
			a[i]=a[i]-a[i+1];
			n++;
			x=i+1;
			break;
		}
	}
	int m=1;
	for(int i=n;i>=x;i--){
		if(a[m]>=a[i]){
			a[m]-=a[i];
			if(c[m]!=c[i]){
				ans+=a[i];
			}
		}else{
			while(a[i]>a[m]){
				a[i]-=a[m];
				if(c[m]!=c[i]){
					ans+=a[m];
				}
				m++;
			}
			a[m]-=a[i];
			if(c[m]!=c[i]){
				ans+=a[i];
			}
		}
	}
	cout<<ans;
				
	return 0;
}
