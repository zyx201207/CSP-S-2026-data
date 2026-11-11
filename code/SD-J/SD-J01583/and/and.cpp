#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int poww[40];
void init(){
	poww[0]=1;
	for(int i=1;i<=30;i++) poww[i]=poww[i-1]*2;
}
bool flag[N];
bool f[40];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	init();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int j=29;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(flag[i]) continue;
			if((a[i]>>j)&1) cnt++;
		}
		if(cnt>=m){
			f[j]=1;
			for(int i=1;i<=n;i++){
				if(flag[i]) continue;
				if(((a[i]>>j)&1)==0) flag[i]=1;
			}
		}
	}
	for(int j=29;j>=0;j--){
		if(f[j]==1){
			ans+=poww[j];
		}
	}
	cout<<ans;
	return 0;
}
