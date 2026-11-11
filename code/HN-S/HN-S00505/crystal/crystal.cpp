#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];//a[i] <= 1e12 
int n,m;//n <= 5e5  m <= 1e18
queue<int> q;
int ans = -1;

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n >>m;
	for(int i = 1; i <= n; i++ ){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	q.push(a[1]);
	
	int p=1,len=1;int cnt=0;
	
	while(!q.empty() && p<=n){
		//cout<<p<<" "<<cnt<<" "<<ans<<endl;
		//入队 
		p++;
		q.push(a[p]);
		cnt = cnt + len * (a[p] - a[p-1]);
		len++;
		//满足条件 记录答案
		
		if(cnt <= m){
			ans = max( ans , len );
		}
		
		//不满足条件 出队
		while(cnt > m && !q.empty()){
			int x= a[p-len+1];
			q.pop();
			len --;
			cnt = cnt - (a[p] - x);
			//cout<<x<<" "<<a[p]<<endl;
		} 
		
	}
	
	cout << ans;
	return 0;
} 
