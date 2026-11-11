#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
bool if_a;
__int128 a[200005];
__int128 read(){
	__int128 ans=0;
	char c=getchar();
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
bool cmp(__int128 a,__int128 b){
	return a>b;
}
bitset<30> b[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(pow(2,log2(a[i]+1))!=a[i]+1) if_a=1;
	}
	if(!if_a){
		sort(a+1,a+1+n,cmp);
		__int128 ans=(1<<30)-1;
		bitset<30> b;
//		for(int i=1;i<=n;i++){
//			b=a[i];
//			cout<<b<<' ';
//		}cout<<'\n';
		for(int i=1;i<=m;i++) ans&=a[i];
		b=ans;
//		cout<<b<<'\n';
		long long an=0;
		for(int i=0;i<=30;i++){
			if(b[i]) an+=pow(2,i);
		}
		cout<<an;
//		print(ans);
	} else{
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++) b[i]=a[i];
		for(int i=30;i>=0;i--){
			bitset<30> ans=(1<<30)-1;
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(b[j][i]){
					cnt++;
					ans&=b[j];
				}
			}
			if(cnt>=m){
				long long an=0;
				for(int i=0;i<=30;i++){
					if(ans[i]) an+=pow(2,i);
				}
				cout<<an;
				return 0;
			}
		}
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/
