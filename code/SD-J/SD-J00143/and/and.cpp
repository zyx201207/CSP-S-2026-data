#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200001],b[200001],sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++)sum=max(sum,a[i]);
		cout<<sum;
		return 0;
	}
	while(b[n+1]==0){
		long long flag=1,ans=0,x=0;
		while(n!=0){
			if(b[flag]==0){
				b[flag]=1;
				break;
			}
			else b[flag]=0,flag+=1;
		}
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				x+=1;
				if(ans==0)ans=a[i];
				else ans=(ans&a[i]);
			}
		}
		if(x==m){
			sum=max(ans,sum);
		}
	}
	cout<<sum;
	return 0;
}//&
