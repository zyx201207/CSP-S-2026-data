#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	//排序 能量从小到大 
	sort(a+1,a+n+1);
	//对齐的水晶 能量从小到大 
	priority_queue<long long,vector<long long>,greater<long long> > pq;
 	//目前要进行几次操作 
	long long cnt=0,num=1;
	//最多可以对齐的水晶数目 
	int ans=0;
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		//对齐这个水晶 要增加的操作次数 
		cnt+=(i-num)*(a[i]-a[i-1]);
		//已经对齐 
		pq.push(a[i]);
		//当前操作次数超过m 
		while(cnt>m && !pq.empty()){
			//取出贡献操作次数最大的水晶（与当前水晶能量差最大） 
			long long u=pq.top();
			//踢出对齐行列 
			pq.pop();
			num++;
			// 减去它所贡献的操作次数 
			cnt=cnt-abs(a[i]-u);
		}
		//当前对齐的水晶数量 
		int s=pq.size();
		//更新最大数量 
		ans=max(ans,s);
	}
	cout << ans << endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
