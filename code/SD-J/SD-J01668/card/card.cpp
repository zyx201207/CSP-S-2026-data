#include<bits/stdc++.h>
using namespace std;
const int Q=3e5+5;
using namespace std;
long long a[Q];
long long b[Q];
long long c[Q];
long long t[Q];
long long vis[Q];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	long long y=lower_bound(a+1,a+1+n,10)-a;
//	cout<<y;
	for(int i=1;i<=n;i++){
		for(int l=i;l<=n;l++){
			c[l]=a[l];
		//	cout<<c[l]<<' ';
		}
	//	cout<<endl;
		for(int j=i;j<=n;j++){
			long long x=lower_bound(c+i,c+j,a[j])-c;
			for(int k=x+1;k<j;k++){
				c[k]=0;
			}
		}
//		for(int l=i;l<=n;l++){
//			cout<<c[l]<<' ';
//		}
	//cout<<endl;
		long long ans=0;
		for(int k=1;k<=n;k++){
			if(vis[c[k]]==0){
				t[c[k]]++;
				if(c[k]==1){
				//	cout<<i<<endl;
				}
				vis[c[k]]=1;
			}
		}
		for(int k=1;k<=m;k++){
			vis[k]=0;
		}
		for(int l=i;l<=n;l++){
			c[l]=0;
		}
	}
	for(int k=1;k<=m;k++){
		cout<<t[k]<<' ';
	}
	return 0;
}

