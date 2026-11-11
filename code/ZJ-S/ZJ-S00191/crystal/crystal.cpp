#include<bits/stdc++.h>
#define int long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans,lst,nw,lf,dw;
//      answer,lst_m,nw_ans,left_side
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//dandiaoduilie(huadongchuangkou)
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	//zhongjianyinggaibuhuibao long long
	lst=m;ans=lf=nw=1;
	for(int i=2;i<=n;i++){
		dw=(a[i]-a[i-1])*nw;
//		cout<<dw<<'\n';
		while(dw>lst){
			lst+=a[i-1]-a[lf];
			lf++;
			nw--;
			dw=(a[i]-a[i-1])*nw;
		}
		lst-=dw;
		nw++;
		if(nw>ans)ans=nw;
//		cout<<dw<<' '<<lst<<' '<<lf<<' '<<nw<<' '<<ans<<'\n';
	}
	cout<<ans<<endl;
	return 0;
}
//zanmeiliangxingchutiren!!!zanmeidayangli!!!chadiancuolaQAQ