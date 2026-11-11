#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,cnt;
struct shu{
	int a,b;
}s[N];
int f(int x){
	int ans=0;
	while(x){
		ans++;
		x=x>>1;
	}
	return ans;
}
int cmp(shu x,shu y){
	return x.b>y.b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i].a;
		s[i].b=f(s[i].a);
	}
	sort(s,s+n,cmp);
	cnt=s[0].a;
	for(int i=0;i<m;i++)
		cnt&=s[i].a;
	cout<<cnt;
	return 0;
}
