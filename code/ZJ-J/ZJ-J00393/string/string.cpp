#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000001];
char c[1000001];
struct node{
	int cnt;
	char bijiao;
};
int ans;
queue<node> q1;
queue<node> q2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		q1.push({a[i],c[i]});
	}
	for(int i=n-1;i>=0;i--){
		q2.push({a[i],c[i]});
	}
	while(!q1.empty()){
		node t1=q1.front();
		node t2=q2.front();
		if(t1.cnt<t2.cnt){
			if(t1.bijiao!=t2.bijiao){
				ans+=t1.cnt;
			}
			q2.front().cnt-=t1.cnt;
			q1.pop();
		}
		else if(t1.cnt==t2.cnt){
			if(t1.bijiao!=t2.bijiao){
				ans+=t1.cnt;
			}
			q1.pop();
			q2.pop();
		}
		else{
			if(t1.bijiao!=t2.bijiao){
				ans+=t2.cnt;
			}
			q1.front().cnt-=t2.cnt;
			q2.pop();
		}
	}
	ans/=2;
	cout<<ans;
	return 0;
}
//Trick||Treat!