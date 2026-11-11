#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
/*
 * hhh wo zuo tian gang kan de 01 bei bao
 * xi wang wo mei ba mo ban qiao cuo
 * =)
 * xian bao li da shang 50 fen zai shuo
 * 
 * yi jiu 2^30 shu ju gui mo
/////////////////////////////////////////////////
 * lao shi shuo de dui
 * define int long long que shi hui bao MLE
 * dan shi
 * wo shang ke cong lai bu ting =)
 * huai le wo wei yun suan mei xue hao!!
 * xiao yang li dou guo le
 * dan shi wo jue de wo de bu liao duo shao fen
 * */
 int n,m;
 int a[N];
 int dp[N];
 bool cmp(int x,int y){
		return x>y;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		//cout<<a[i]<<' ';
		dp[i]=a[1];
	}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			//if(dp[j]==0) 
			s=dp[j-1] & a[i];
			//cout<<s<<endl;
			if(j==1) {
				dp[j]=dp[j]&a[i];
			}
			else dp[j]=max(dp[j-1],s);
		}
	}
	cout<<dp[m];
    return 0;
}
