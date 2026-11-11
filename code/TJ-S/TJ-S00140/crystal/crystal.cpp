#include <bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1,cnt=0;
	cin >>n >>m;
	if(m==0 or n==1){
		cout <<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	if(n>5000){
		for(int i=2;i<=n;i++){
			long long tep=a[i]-a[i-1];
			if(tep<=m){
				if(tep*(i-1)<=m){
					m-=tep*(i-1);
					ans+=1;
				}
				else{
					break;
				}
			}
			else break;
		}
		cout <<ans;
	}
	else{
		for(int i=1;i<=n-1;i++){
			long long c=m;
			for(int j=i;j<=n-1;j++){
				if(c>=b[j]*(j-i+1)){
					c-=b[j]*(j-i+1);
					if(j-i+1>cnt)cnt=j-i+1;
				}
				else break;
			}
		}
		ans=cnt+1;
		cout <<ans;
	}
	return 0;
} 
