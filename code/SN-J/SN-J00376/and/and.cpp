#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const ll maxn=2e5+10;
const ll inf=1e18+10;
int n,m,ans=0;
int a[maxn];
queue<int>q;
queue<int>qq;
queue<int>qqq;
queue<int>q1;
int t[maxn][40];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if((1<<j)<=a[i]){
				t[i][j]=1;
				a[i]-=(1<<j);
			}
			else{
				t[i][j]=0;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=30;j>=0;j--){
//			cout<<t[i][j];
//		}
//		cout<<"\n";
//	} 
	for(int i=1;i<=n;i++){
		q.push(i);
		qq.push(i);
	}
	for(int j=30;j>=0;j--){
		int cnt=0;
//		cout<<"--------------\n";
		while(!q.empty()){
			int i=q.front();
			q.pop();
//			cout<<i<<" "<<t[i][j]<<"\n";
			if(t[i][j]==1){
				cnt++;
				q1.push(i);
			}
		}
//		cout<<"--------------\n";
		if(cnt>=m){
			ans+=(1<<j);
			while(!qq.empty()){
				qq.pop();
			}
			while(!q1.empty()){
				qq.push(q1.front());
				q.push(q1.front());
				q1.pop();
//				cout<<q.front()<<" ";
			}
//			cout<<"\n";
		}
		else{
			while(!q1.empty()){
				q1.pop();
			}
			while(!q.empty()){
				q.pop();
			}
			while(!qq.empty()){
//				cout<<qq.front()<<"-";
				q.push(qq.front());
				qqq.push(qq.front());
				qq.pop();
			}
//			cout<<"\n";
			while(!qqq.empty()){
				qq.push(qqq.front());
				qqq.pop();
			}
		}
	}
	cout<<ans;
	return 0;
}
