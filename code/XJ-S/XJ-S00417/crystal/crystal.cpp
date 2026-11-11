#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
long long int n,m,m1;
long long int s[N],vis[N];
long long int ty[N];
long long int spc=0,f=0,ans=0,dans=0,cnt=0,mx=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>s[i];
		if(i==2) {
			spc=s[i]-s[i-1];
		}
	}
	sort(s+1,s+n+1);
	for(int i=2; i<=n; i++) {
		if(spc!=s[i]-s[i-1]) {
			f=1;
		}
	}
	if(f==0) {
		for(int i=1; i<=n; i++) {
			ans+=i*spc;
			if(ans>m) {
				cout<<i;
				return 0;
			}
		}
		if(ans<m) {
			cout<<n;
			return 0;
		}
	}
//暴力 
	vis[0]=0;
	vis[1]=0;
	for(int i=2; i<=n; i++) {
		vis[i]=s[i]-s[i-1];
	}
	for(int i=1;i<=n;i++){
		ans=0;//双重递加
		dans=0; 
		for(int j=i;j>=1;j--){
			ans+=vis[j];
			dans+=ans;
			cnt=j;
			if(dans>m){
				break;
			}	
		}
		mx=max(mx,i-cnt+1);
//		printf("mx=%d,cnt=%d,i=%d,dans=%d\n",mx,cnt,i,dans);
	}
	cout<<mx;
	return 0;
} 
// 特殊性质解决  sorce:30;
// 差值排序不可取


/*



1 2 4 8 9
  1 2 4 1


-3 -1 2 2 7
    2 3 0 5


*/
