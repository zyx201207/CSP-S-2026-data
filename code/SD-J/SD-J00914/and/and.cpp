#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,m,a[200003],ans,t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)t++;
	}if(n-m<t){
		cout<<0;
		return 0;
	}
	for(int k=30;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++)if((a[i]>>k)%2==1)cnt++;
		if(cnt>=m){
			for(int i=1;i<=n;i++)if((a[i]>>k)%2==0)a[i]=0;
			ans+=(1<<k);
		}
	}cout<<ans;
}
