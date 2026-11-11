#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long a[N];
//long long dp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof a);
		long long n,sum=0,d;
		if(c==13||c==14){
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
				cin>>a[i];
				
				if(a[i]-d>0){
					long long u=lower_bound(a+1,a+1+n,a[i]-d)-a;
					dp[u]=i;
					if(u>0)sum+=(n-i);
					
				}
				
			}
			cout<<sum<<endl;
		}
		if(c==11||c==12){
			long long ch,mos;
			cin>>n>>d;
			cin>>a[1];
			for(long long i=2;i<=n;i++){
				cin>>a[i];
				ch=a[i]-a[i-1];
				mos=d/ch;
			}
			if(mos==0)cout<<0<<endl;
			else cout<<n-mos*2+1<<endl;
		}
	}
	
//	while(t--){
//		long long n,d;
//		cin>>n>>d;
//		for(long long i=1;i<=n;i++){
//			cin>>a[i];
//			for(long long j=i;j>=0;j--){
//				if(a[i]-a[j]<=d)dp[j][i]=1;
//				else break;
//			}
//		}
//	}
	return 0;
} 
//freopen别注释；测试输出要删去；
//文件夹、文件名写对了吗；
//freopen输入输出文件名写对了吗 
//函数return了吗  
//13 1 5 2 1 2 3 4 5
