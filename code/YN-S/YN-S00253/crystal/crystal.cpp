#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N];
bool A=1,B=1;
//long long c[N];
//long long q[N];
long long ans=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]!=a[i-1]){
			A=0;
		}
		if(i!=1&&i!=2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			B=0;
		}
	}
	if(A){
		//cout<<'A'<<'\n';
		cout<<n<<'\n';
		return 0;
	}
	if(B){
		//cout<<'B'<<'\n';
		cout<<m/(a[2]-a[1])<<'\n';
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long nl=m,sum=1;
		for(int j=i-1;j>=1;j--){
			//cout<<a[i]-a[j]<<' ';
			if(a[i]-a[j]>nl){
				break;
			}else{
				sum++;
				nl=nl-(a[i]-a[j]);
			}
		}
		//cout<<'\n';
		ans=max(sum,ans);
	}
	cout<<ans<<'\n';
//	c[1]=q[1]=0;
//	for(int i=2;i<=n;i++){
//		c[i]=a[i]-a[i-1];
//		q[i]=c[i]+c[i-1];
//	}
//	for(int i=1;i<=n;i++){
//		cout<<q[i]<<'\n';
//	}
	return 0;
}
