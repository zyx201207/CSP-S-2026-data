#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=2e5+10;
int n,m;
int a[Maxn]; 
bool cmp(int x,int y){
	return x>y;
}
int sum[Maxn][40];
void solve(int x,int op){//拆位存储 
	for(int i=1;i<=40;i++){
		sum[op][i]=x%2;
		x/=2;
	}
}
signed main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//二进制 nlogn 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		solve(a[i],i);
	}
	//检验拆位
//	for(int i=1;i<=n;i++){
//		for(int j=20;j>=1;j--){
//			cout<<sum[i][j];
//		}
//		cout<<"\n";
//	}
	vector<int> v;//剩余可用的数字的编号 
	for(int i=1;i<=n;i++)	v.push_back(i);
	int ans=0; 
	for(int i=35;i>=0;i--){
		if(v.size()<m)	break;
		vector<int> nv; 
		int cnt=0;
		for(auto it:v){
			if(sum[it][i]){
				nv.push_back(it);
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=(1<<(i-1));
			v=nv;
		}
	}
	cout<<ans;
	return 0; 
} 
/*
4 2
3 15 12 12
*/
