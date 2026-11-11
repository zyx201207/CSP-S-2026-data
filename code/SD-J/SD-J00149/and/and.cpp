#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans,k,f[35];
struct Node{
	int a,b,c[35];
}s[N];
void work(int x,int id){
	int cnt=0;
	while(x){
		s[id].c[++cnt]=(x&1);
		if(x&1) f[cnt]++;
		x>>=1;
	}
	s[id].b=cnt;
}
bool cmp(Node x,Node y){
	return x.b>y.b;
}
bool cmp_(Node x,Node y){
	return (x.a&k)>(y.a&k);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
		work(s[i].a,i);
	}
	sort(s+1,s+1+n,cmp);
	for(int i=s[m].b;i>=1;i--){
		if(f[i]>=m){
			k=(1<<i)-1,ans=(1<<30)-1;
			sort(s+1,s+1+n,cmp_);
			for(int i=1;i<=m;i++) ans&=s[i].a;
			cout<<ans;
			return 0;
		}
	}
	cout<<0;
	return 0;
} 
