#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,cnt=1;
long long m,ans;
long long a[N],b[5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(a[i]==i){
			cnt++;
		}
	}
	if(cnt==n){
		for(int i=1;i<=n/2+1;i++){
			if(i<=m){
				m-=i;
				ans++;
			}
		}
		cout<<ans+1;
		return 0;
	}
	else{
		int x=n/2+1,minn=N;
		for(int i=1;i<=n;i++){
			b[i]=a[x]-a[i];
		}
		for(int i=1;i<=n;i++){
			if(b[i]>=0){
				m-=b[i];
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
