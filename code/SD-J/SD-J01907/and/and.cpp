#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N],p[N],c[N],vis[N][40];
multiset<long long> s,t;
void oi(int x){
	for(int i=0;i<=x;i++){
		c[i]=0;
		for(auto o:s){
			if(o&p[i]==p[i]){
				c[i]++;
			}
		}
	}
}
void maind(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.insert(a[i]);
	}
	p[0]=1;
	for(int i=1;i<=32;i++)p[i]=p[i-1]*2;
	for(int i=0;i<=32;i++){
		for(int j=1;j<=n;j++){
			vis[j][i]=a[j]&p[i];
			if(vis[j][i]==p[i]){
				c[i]++;
			}
		}
	}
	long long l=(p[32]*2ll)-1ll;
	for(int i=32;i>=0;i--){
		if(c[i]>=m){
			t.clear();
			for(auto o:s){
				if(o&p[i])t.insert(o);
			}
			s=t;
			oi(i);
		}
	}
	long long h=(p[32]*2ll)-1ll;
	for(auto o:s){
		m--;
		if(m<0)break;
		h&=o;
	}
	cout<<h;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		maind();
	}
	return 0;
}

