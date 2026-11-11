#include<bits/stdc++.h>
using namespace std;

#define int long long  
const int N=5e5+5;


int n;
long long m;
long long a[N];
long long sum[N];

bool check(int l,int r){
	
	long long sumx=(r-l+1)*a[r];
	
	if(sumx-sum[r]+sum[l-1]<=m){
		return true;
	}
	else{
		return false;
	}
	
}

signed main(){
	
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	
	int ans=0;
	
	for(int i=1;i<=n;i++){
	
		int l=i,r=n+1;
		
		while(l<=r){
			
			int mid=(l+r)>>1;
			
			if(check(i,mid)){
				
				l=mid+1;
			} 
			
			else{
				r=mid-1;
			}
		} 
		
		int len=(l-i);
		
		ans=max(len,ans);
	}
	
	cout<<ans;
} 
/*
排序+二分 
14:50 切掉T1

17:25 不打了，其他的基本不会

期望得分 234 pts(？还是顺子)，觉得我能拿到 7 勾吗？
服了啊，开场 1h 200pts,接下来 2h 就 34 pts。

17:30

开始检查T1，避免挂分（模拟赛天天挂100+pts正赛别挂啊） 

不是这大样例咋不是满数据啊，那得好好检查了。

算了T1空间完全够，define in long long 吧，我不要挂分。 

复查大样例通过。

-> T2

17:57 开始检查文件夹。

文件夹检查完了，检查下命名。

18:00 不是谁手机铃声啊，雨姐来袭，没绷住

18:01 不是T1真命错名啊，幸好幸好。 

18:03 OK检查完毕，打开freopen。 

18:05 饼干-1。

18:06 不行脑袋里全是大东北，赶紧默唱两遍清心咒 

18:13 高僧预测难度 橙绿蓝紫，前两题水完了。 
*/
