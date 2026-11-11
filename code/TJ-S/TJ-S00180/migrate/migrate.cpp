#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000005
int c,T;
int n,d;
int a[N],b[N],l[N],r[N];
queue <int> q;
stack <int> s;
bool check(int x,int y){
	while (q.size()) q.pop();
	while (s.size()) s.pop();
	for (int i=x;;i=r[i]){
		if (i<y) q.push(i);
		else{
			q.push(y);
			break;
		}
		if (i==r[i]) return 0;
	}
	for (int i=y;;i=l[i]){
		if (x<i) s.push(i);
		else{
			s.push(x);
			break;
		}
		if (i==l[i]) return 0;
	}
	if (q.size()!=s.size()) cout<<"How could we got there?\n"<<x<<" "<<y<<" "<<T,exit(0);
	int cnt=0;
	while (q.size()){
		cnt+=q.front()-s.top();
		q.pop(),s.pop();
	}
	return cnt==1;
}
void work(){
	scanf("%lld %lld",&n,&d);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),b[n-i+1]=-a[i];
	for (int i=1;i<=n;i++) r[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
	for (int i=1;i<=n;i++) l[n-i+1]=n-(upper_bound(b+1,b+1+n,b[i]+d)-b-1)+1;
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			ans+=check(i,j);
		}
	} 
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%lld %lld",&c,&T);
	while (T--) work();
	return 0;
}
