#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],sum,num=1,y=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(y==1&&i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			y=0;
		}
	}
	sort(a+1,a+n+1);
	if(y==1){
		long long c=a[2]-a[1];
		long long b=m/c,d;
		d=int(sqrt(1+8*b)-1);
		d=d/2;
		sum=d+1;
	}
	else{
		for(int i=n;i>=num;i--){
			long long m_=m,n_=i-1,ans=1;
			while(m_>=a[i]-a[n_]&&n_>=1){
				m_-=a[i]-a[n_];
				n_--;
				ans++;
			}
			if(ans>sum){
				sum=ans;
			}
			if(sum>=i-1){
				break;
			}
			num=sum+1;
		}	
	}
	cout<<sum;
	return 0;
}
