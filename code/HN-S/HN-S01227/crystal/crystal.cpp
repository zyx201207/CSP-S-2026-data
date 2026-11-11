#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],s[500005],dd;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	s[1]=0;//s[i]表示a[i]若为合并目标数 所要的操作次数 
	for(int i=1;i<=n;i++){
		s[i]=(a[i]-a[i-1])*(i-1)+s[i-1];
		if(s[i]>m){
			dd=i-1;//能合并的目标数下标 
			break;
		}
	}
	cout<<dd;
	return 0;
}
