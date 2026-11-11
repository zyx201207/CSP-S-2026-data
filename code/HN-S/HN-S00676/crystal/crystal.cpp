#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[100005],b[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(b[i]==b[j]){
				if(a[i]+a[j]<=a[i]+a[j+1]){
					ans++;
					a[i]=a[i]+a[j+1];
					b[i]++;
					b[j]++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

