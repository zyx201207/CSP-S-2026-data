#include<bits/stdc++.h>
using namespace std;
long long a[500015],b[500015],n,m,x,cnt=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=2;i<=n;i++){
		while(i-cnt>0&&(cnt+1)*a[i]<=b[i]-b[i-cnt-1]+m){
			cnt++;
		}
	}
	cout<<cnt;
}