#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1,mxans=0;
	sort(a+1,a+n+1);
	for(int i=2;i<n&&m>0;i++){
		for(int j=1;j<i;j++){
			if(m-a[i]+a[j]>=0){
				m=m-a[i]+a[j];
				a[j]=a[i];
			}
			else{
				m=0;
				break;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		mxans=max(mxans,ans);
		if(a[i]==a[i-1]){
			ans++;
		}
		else{
			ans=1;
		}
	}
	cout<<mxans;
} 
