#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n,m,a[N],s[N],ans=0;
bool flag=true;
int main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	s[1]=a[2]-a[1];
	for(int i = 2;i<n;i++){
		s[i]=a[i+1]-a[i];
		if(s[i]!=s[i-1]) flag=false;
	}
	sort(a+1,a+n+1);
	if(flag){
		long long y = s[1],cnt=0,cost=0;
		long long now = y;
		while(cost<=m){
			cost+=now;
			now+=y;
			cnt++;
		}
		cout << cnt;
	}else{
		for(int i = 1;i<=n;i++){
			long long sum=0,x=m;
			for(int j = i;j>=1;j--){
				if(a[i]-a[j] <= x){
					x-=a[i]-a[j];
					sum++;
				}
			}
			ans=max(ans,sum);
		}
		cout << ans;
	}
	return 0;
} 
