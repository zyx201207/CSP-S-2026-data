#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int f[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long d=a[2]-a[1],ans=0;
	bool flag=true;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			flag=false;
			break;
		}
	}
	if(flag==true){
		int j=0;
		long long k=m;
		while(k-d*j>=0&&j<n){
			k-=d*j;
			j++;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	f[1]=1;
	for(int i=2;i<=n;i++){
		int l=i-1,sum=1;
		long long z=m;
		while(z-(a[i]-a[l])>=0&&l>=1){
			z-=a[i]-a[l];
			l--;
			sum++;
		}
		f[i]=max(f[i-1],sum);
	}
	cout<<f[n];
	return 0;
}
