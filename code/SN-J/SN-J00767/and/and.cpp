//SN-J00767 汤佳忆 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int cmp[50],a[N],jj=30;
vector<int> f[40];
bool cmpp(int a,int b){return a>b;}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	int cnt=1;
	for(int i=1;i<=30;++i)cnt*=2;
	sort(a+1,a+1+n,cmpp);
	//cout<<cnt;
	while(1){
		for(int i=1;i<=n;++i){
			if(a[i]>=cnt){
				f[jj].push_back(a[i]);
				a[i]-=cnt;
				cmp[jj]++;
			}
		}
		if(cnt==0){break;}
		jj--;
		cnt/=2;
	}
	//for(int i=30;i>=0;--i)cout<<i<<" "<<cmp[i]<<"\n";
	int x=0;
	for(int i=30;i>=0;--i){
		if(cmp[i]>=m){
			x=i;
			break;
		}
	}
	//cout<<"x="<<x;
	int ans=f[x][0];
	for(int i=1;i<m;++i)ans&=f[x][i];
	if(x==0)cout<<0;
	else cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12
*/
