#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	long long minn=5000000000000000000;
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		if(b[i]<minn){
			minn=b[i];
		}
	}
	int c=1;
	while(minn<=m&&c<m){
		minn=5000000000000000000;
		c++;
		for(int i=1;i<=n-c;i++){
			long long d=0;
			for(int j=1;j<=c;j++){
				d+=b[j+i-1]*j;
			}
			if(d<minn){
				minn=d;
			}
		}
	}
	cout<<c<<endl;
	return 0;
}
