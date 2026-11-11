#include<bits/stdc++.h>
using namespace std;
struct box{
	long long x,sum;
};
long long n,d,a[2000010],res=0;
bool check(long long x,long long y){
	vector<box>s(2000010);
	for(int i=x;i<=y;i++){
		s[i]={(long long)1e15,0ll};
	}
	queue<box>q;
	q.push({x,1});
	while(!q.empty()){
		auto [now,sum]=q.front();
		q.pop();
		for(int i=now;i<=y;i++){
			if(a[i]-a[now]>d){
				break;
			}
			if(sum+1<s[i].x){
				s[i].x=sum+1;
				s[i].sum=1;
				q.push({i,sum+1});
			}else if(sum+1==s[i].x){
				s[i].sum++;
			}
		}
	}
	if(s[y].sum==2){
		return 1;
	}
	return 0;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	res=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j)){
				res++;
			}
		}
	}
	cout<<res<<endl;
}
int main(){
//	freopen("E:/down/migrate/migrate3.in","r",stdin);
//	freopen("E:/down/migrate/migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}