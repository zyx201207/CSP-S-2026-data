#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans=0;
int z[N],vis[N];
void ch(int t){
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		if(a[i]/z[t]%2==0) vis[i]=1;
	}
}
signed main(){
	/**/
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	z[1]=1;
	for(int i=2;i<=30;i++){
		z[i]=2*z[i-1];
	}
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	
	int k;
	for(int i=30;i>=1;i--){
		if(a[n]<z[i]) continue;
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]/z[i]%2==1) cnt++;
		}
		if(cnt>=m){
			k=i;
			break;
		}
		
	}
	//cout << k << "!!!\n";
	
	int sum=n;
	for(int i=k;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==1){
				continue;
			}
			if(a[j]/z[i]%2==1) cnt++;
			//if(i==3) cout << "###" << a[j] << ' ' << vis[j]  << ' ' << a[j] <<"###"  << endl;
		}
		if(cnt>=m){
			ans+=z[i];
			ch(i);
		}
	}
	cout << ans;
	//int a=3&15;
	return 0;
} 
/*
3  | 0011
5  | 0101
12 | 1100
12 | 1100

31 | 11111
3  | 00011
1  | 00001
15 | 00111
7  | 00011

3
  #
01011x
01001x
10011x
10100
00110
00101
00111

*/
