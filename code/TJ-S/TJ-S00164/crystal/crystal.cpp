#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll n,m,a[N],s[N],len=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
//		cout<<s[i]<<' ';
	}
	for(int i=1;i<=n;++i){
		if(i+len-1>n) break;
		while(i+len<=n&&s[i+len]-s[i]-(i-1)*(a[i+len]-a[i])<=m){//next
			len++;
		}
	}
	cout<<len;
	return 0;
}
//调了2h，终于过了/kel
//思路没想好，有小细节没有好好想（哭
//这个月我一定狂练贪心！qwq
