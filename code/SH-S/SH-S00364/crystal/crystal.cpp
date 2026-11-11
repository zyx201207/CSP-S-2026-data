#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[500010] = {};
long long n,m;
int ans=0;
int b[500010] = {};

int main(){
	freopen("crystal.in","r",stdin);
	cin>>n>>m;
	if(m==0){
		cout<<m<<endl;
		return 0 ;
	}
	if(n>5000){
		int sum =-1,s=1,x=m;
		while(x>=0){
			x-=s;
			sum++;
			s++;
		}
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;--i){
		int sum=1,x=m;
		for(int j=i-1;j>=1;--j){
			if(x<=0){
				continue;
			}
			else{
				x-=a[i]-a[j];
				sum++;
			
			}
		}
		a[i] = sum;
	}
	for(int i=1;i<=n;++i){
		ans = max(ans,a[i]);
	}
	cout<<ans<<endl;
	return 0;
	freopen("crystal.out","w",stdout);
} 
