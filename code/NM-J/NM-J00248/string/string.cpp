#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n,sum=0,ans=0;
    cin>>n;
    long long a[n+5];
    char c[n+5];
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum=sum+a[i];
	}
	long long j=n,i=1;
	while(1){
		if (i==j){
			cout<<ans;
			return 0;
		}
		if(a[i]>a[j]){
			if(c[i]!=c[j]){
				if((ans+a[j])>=(sum/2)){
					cout<<(sum/2);
					return 0;
				}
				ans=ans+a[j];
			}
			a[i]=a[i]-a[j];
			j=j-1;
		}
		else{
			if(c[i]!=c[j]){
				if((ans+a[i])>=(sum/2)){
					cout<<(sum/2);
					return 0;
				}
				ans=ans+a[i];
			}
			a[j]=a[j]-a[i];
			i=i+1;
		}
	}
    return 0;
}


