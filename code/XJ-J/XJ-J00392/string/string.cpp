#include<bits/stdc++.h>
using namespace std;
long long int n,x,a[2*100010],sum;
char b[2*100010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n/2;i++){
		if(a[i]==a[n+1-i]&&b[i]==b[n+1-i]){
			break;
		}else if(b[i]==b[n+1-i]){
			break;
		}else if(a[i]==a[n+1-i]){
			sum+=a[i];
		}else{
			if(a[i]>a[n+1-i]){
				sum+=a[i];
				a[n+1-i-1]=a[n+1-i-1]-a[i]+a[n+1+i];
			}else{
				sum+=a[n+1-i];
				a[i+1]=a[i+1]-a[n+1-i]+a[i];
			}
		}
	}
	cout<<sum;
	return 0;
}