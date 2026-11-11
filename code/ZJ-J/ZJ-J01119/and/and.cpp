#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int M=200005;
int n,m,f[M];
struct qjj{
	int a;
	string s;
	bool v;
}q[M];
string fun(int x){
	string s=" ";
	while(x){
		s+=x%2;
		x/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}
bool vois(int x){
	for(int i=0;i<q[x].s.size();i++){
		if(q[x].s[i]=='0'){
			return 0;
		}
	}
	return 1;
}
bool cmp(qjj x,qjj y){
	return x.a>y.a;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ma=INT_MIN;
	bool vis=1;
	for(int i=1;i<=n;i++){
		cin>>q[i].a;	
		ma=max(ma,q[i].a);	
		q[i].s=fun(q[i].a);
		q[i].v=vois(i);
		if(!q[i].v){
			vis=0;
		}
	}
	sort(q+1,q+n+1,cmp);
	f[1]=q[1].a;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]*q[i].a;
	}
	if(m==n){
		cout<<f[n];
		return 0;
	}else if(m==1){
		cout<<ma;
		return 0;
	}else if(vis){
		cout<<q[n-m+1].a;
		return 0;
	}else cout<<q[n-m+1].a;
	return 0;
}