#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long mi=LLONG_MAX,ma=LLONG_MIN;
	bool f=true,f2=false;
	long long xxx=a[1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2 && f==true){
			if(xxx!=a[i]){
				f=false;
			}
		}
		if(i>=2 && f2==false){
			if(a[i]<=a[i-1]){
				f2=true;
			}
		}
	}
	if(f==true){
		cout<<n;
		return 0;
	}
	if(f2==true){
		sort(a+1,a+n+1);
	}
	mi=a[1],ma=a[n];
	long long sum=0,w=1,i=a[1];
	long long ans=0;
	while(m>=0){
		if(m>=sum){
			m-=sum;
			if(i==a[sum+1]){
				while(i==a[sum+1]){
					sum++;
				}
			}
			i++;
		}
		else{
			ans=sum;
			break;
		}
		if(m==0){
			ans=sum;
			break;
		}
	}
	cout<<ans;
	return 0;
}
////Oct31==Dec25?
