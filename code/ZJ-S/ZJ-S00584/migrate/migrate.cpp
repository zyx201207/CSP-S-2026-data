#include<bits/stdc++.h>//T3->migrate
using namespace std;
const int N=10010;
int t,n,jp[N],d;
long long a[N],ret=0;//jp->jump
struct node {
	int mi,ways;
}dp[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;//吃c 
	while(t--){//1e5
		cin>>n>>d;
		for(int i=0;i<n;i++){//2e6
			cin>>a[i];
		}//预处理每个点能跳到哪 
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			int j=i+1;
			for(;j<n;j++){
				if(a[i]+d<a[j])break;
				dp[i][j].mi=1;
				dp[i][j].ways=1;
			}jp[i]=j-1;//骗 
			/*
			int l=i,r=n-1;
			while(l<r){
				int mid=(l+r+1)/2;
				if(a[i]+d>=a[mid]){
					l=mid;
				}else r=mid-1;
			}jp[i]=l;//二分 
			*/
		}
		for(int len=3;len<n;len++){//2e6,len当下标差 
			for(int i=0;i+len<n;i++){//4e12了，超时待优化，大约骗40 
				long long num=i;
				while(num<i+len){
					num=jp[num];
					dp[i][i+len].mi++;
				}for(int j=i+1;j<len;j++){//没招了骗点先 
					if(dp[i][j].mi+dp[j][i+len].mi){
						dp[i][i+len].ways+=dp[i][j].ways*dp[j][i+len].ways;
					}
				}if(dp[i][i+len].ways==2)ret++;
			}
		}cout<<ret<<endl;
	}
	return 0;
}
