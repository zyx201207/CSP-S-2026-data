#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long mx=-1e5;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	if(m==1){
		cout<<mx;
	}else if(m==n){
		long long sum=0;
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}else if(m==2){
		long long mxn=-1e5;
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++){
				mxn=max(mxn,a[i]&a[j]);
			}
		}
		cout<<mxn;
	}
	return 0;
}
