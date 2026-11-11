#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int n,m,a[N],ans;
deque<int> q;
void solve1(){
	for(int k=2;k<=n;k++){
		int sum=1,p=m;
		for(int i=k-1;i>=1;i--){
			if(a[k]-a[i]<=p)p-=a[k]-a[i],sum++;
			else break;
		}
		ans=max(ans,sum);
	}
	cout<<ans<<"\n";
	return;
}
void solve2(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(q.empty())q.push_back(a[i]);//队为空 
		else if(sum+q.size()*(a[i]-q.back())<=m){
			//cout<<1<<" ";
			sum+=q.size()*(a[i]-q.back());
			q.push_back(a[i]);
			
		}//可以直接插入 
		else {
			//cout<<2<<" ";
			sum+=(q.size()-1)*(a[i]-q.back())-(q.back()-q.front());
			q.pop_front();
			q.push_back(a[i]);
			while(sum>m){
				sum-=q.back()-q.front();
				q.pop_front();
			}
		}
		if(q.size()>ans)ans=q.size();
		/*for(int i=0;i<q.size();i++)cout<<q[i]<<" ";
		cout<<" "<<sum; 
		cout<<"\n";*/
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=5000){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
//6 12 -3 -1 2 4 6 8
