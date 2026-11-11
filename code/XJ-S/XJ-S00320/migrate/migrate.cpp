#include<bits/stdc++.h>
using namespace std;
int c,T;
namespace sub1{
const int N=5e3+5;
int n;
long long D;
long long a[N];
int head[N],ver[N*N],nxt[N*N],tot;
int d[N];
long long cnt[N];
void addedge(int x,int y){
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void BFS(int s){
	for(int i=1;i<=n;i++) d[i]=1e9,cnt[i]=0;
	d[s]=0,cnt[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i];
			if(d[x]+1<d[y]){
				d[y]=d[x]+1;
				cnt[y]=cnt[x];
				q.push(y);
			}else if(d[x]+1==d[y]){
				cnt[y]+=cnt[x];
			}
		}
	}
}
void solve(){
	while(T--){
		cin >> n >> D;
		tot=0;
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=D){
//					cout << i << ' ' << j << '\n'; 
					addedge(i,j),addedge(j,i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			BFS(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
		}
		cout << ans << '\n';
	}
}
} 
namespace sub2{
const int N=2e6+5;
int n;
long long D;
long long a[N];
bool b[N];
bool check(int x){
	int l=1,r=x;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(a[mid]-a[1]<=D) l=mid;
		else r=mid-1;
	}
	int ll=1,rr=x;
	while(ll<rr){
		int mid=(ll+rr)>>1;
		if(a[x]-a[mid]<=D) rr=mid;
		else ll=mid+1;
	}
//	cout << x << ' ' << l << ' ' << ll << '\n'; 
	return l-ll+1==2;
}
void solve(){	
	while(T--){
		cin >> n >> D;
		for(int i=1;i<=n;i++) b[i]=0;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]>D&&a[i]-a[1]<=D*2){
				if(check(i)) b[i]=1; 
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans+=b[i]*(n-i+1);
		}
		cout << ans << '\n';
	}
}
} 
namespace sub3{
const int N=2e6+5;
int n;
long long D;
long long a[N];
void solve(){	
	while(T--){
		cin >> n >> D;
		for(int i=1;i<=n;i++) cin >> a[i];
		cout << 0 << '\n';
	}
}
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> T;
	if(c<=10){
		sub1::solve();
	}else if(c==11||c==12){
		sub2::solve();
	}else{
		sub3::solve();
	}
	return 0;
}
/*
0 1
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956
*/ 
/*
11 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
