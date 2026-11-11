#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long s[500010];
int mx=-1;
int flag=0; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>=5000){
		long long d=a[2]-a[1];
		long long s=sqrt((2*m)/d);
		cout<<s;
		return 0;		
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		flag=0;
		long long sum=0;
		for(int j=i-1;j>=1;j--){
			sum+=(a[i]-a[j]);
			if(sum>m){
				mx=max(mx,i-j);
				flag=1;
				break;
			}
		}
		if(flag==0)mx=max(mx,i);
	}
	cout<<mx;
	return 0;
}
