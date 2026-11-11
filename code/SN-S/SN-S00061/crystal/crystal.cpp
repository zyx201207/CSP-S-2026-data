#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[100000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,temp;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long maxa=-1,ans=0;
	sort(a+1,a+1+n);
	if(n>=5001){
		for(long long i=1;i<=m;i++){
			if(i*(i-1)>=(a[2]-a[1])*2*m){
				cout<<i/(a[2]-a[1]);
				return 0;
			}
		}
	}
	for(int i=2;i<=n;i++){
		temp=m;
		ans=0;
		for(int j=i-1;j>=1;j--){
			if(temp-a[i]+a[j]>=0){
				temp-=a[i];
				temp+=a[j];
				ans++;
			}
			maxa=max(maxa,ans);
		}
	
	}
	cout<<maxa+1;
	return 0;
} 
