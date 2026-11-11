#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N];
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=abs(a[i]-a[j]);
		}
		sort(b+1,b+1+n);
		int sum=0;
		bool flag=1;
		for(int j=1;j<=n;j++){
			sum+=b[j];
			if(flag){
				if(sum>m){
					ans=max(ans,j-1);
					flag=0;
				}else if(sum==m){
					ans=max(ans,j);
					flag=0;
				}
			}
			if(j==n && sum<m){
				ans=n;
			}
		}
	}
	cout<<ans;
	return 0;
} 
