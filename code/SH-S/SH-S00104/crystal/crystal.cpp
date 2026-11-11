#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int left=m,ans=0;
	sort(a+1,a+n+1);
	bool flag=true;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]){
			flag=false;
			break;
		}
	}
	if(flag){
		for(int i=n;i>=1;i--){
			if((i*i+i)*(a[2]-a[1])<=2*m){
				cout<<i+1;
				return 0;
			}
		}
	}
	int b[n+1],c[n+1];
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	for(int i=2;i<=n;i++){
		left=m;
		int sum=1;
		for(int j=i-1;j>=1;j--){
			if(left>=a[i]-a[j]){
				sum++;
				left-=a[i]-a[j];
			}
			else break;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
