#include<bits/stdc++.h>
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x/gcd(x,y)*y)
using namespace std;
const int MX=1073741823;
struct node{
	int a,b[35];
}a[200005];
bool cmp(node a,node b){
	return a.a<b.a;
}
queue<node>q;
void solve(){
	int n,m,res=0,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		a[i].a=t;
		int cnt=0;
		while(t){
			a[i].b[cnt++]=t&1;
			t>>=1;
			res=max(res,cnt);
		}
	}
	sort(a+1,a+n+1,cmp);
	int flag=1;
	for(;res>=0;res--){
		int cnt=0,sum=MX;
		for(int j=1;j<=n;j++){
			if(a[j].b[res]){
				cnt++;
				sum=sum&a[j].a;
			}
		}
		if(cnt==m&&flag){
			cout<<sum;
			return;
		}
		if(cnt>m&&flag){
			flag=0;
			for(int j=1;j<=n;j++){
				if(a[j].b[res]){
					q.push(a[j]);
				}
			}
			num+=1<<res;
			break;
		}
	}
	if(flag){
		cout<<0;
	}
	for(res--;res>=0;res--){
		int cnt=0;
		for(int j=1;j<=q.size();j++){
			node t=q.front();
			if(t.b[res]){
				cnt++;
			}
			q.push(t);
			q.pop();
		}
		if(q.size()==m){
			int sum=MX;
			int ln=q.size();
			for(int j=1;j<=ln;j++){
				node t=q.front();
				sum=sum&t.a;
				q.pop();
			}
			cout<<sum;
			return;
		}
		if(cnt==m){
			int sum=MX;
			int ln=q.size();
			for(int j=1;j<=ln;j++){
				node t=q.front();
				if(t.b[res]){
					sum=sum&t.a;
				}
				q.pop();
			}
			cout<<sum;
			return;
		}
		if(cnt>m){
			int ln=q.size();
			for(int j=1;j<=ln;j++){
				node t=q.front();
				if(t.b[res]){
					q.push(t);
				}
				q.pop();
			}
			num+=1<<res;
		}
	}
	cout<<num;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

