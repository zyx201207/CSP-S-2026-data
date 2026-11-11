#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define to0(x) memset(x,0,sizeof x)
#define to_1(x) memset(x,-1,sizeof x)
#define toinf(x) memset(x,0x3f,sizeof x)
#define Debug cout<<"DEBUG\n";
#define Deon(x) cout<<"DEBUG:"<<x<<'\n';
#define pb(x) push_back(x)
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

const int N = 2e5+5;
int n,m,a[N],ct[35];
set<int> b[35],s,tmp;

bool _jiao(int k) {
	tmp.clear();
	for(auto i:s) {
		if(b[k].count(i)!=0) {
			tmp.insert(i);
		}	
	}return tmp.size()>=m;
}
void U(int k) {
	s.clear();
	for(auto i:tmp) s.insert(i);
}

int main() {
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		for(int j=0;j<=30;j++) {
			if(a[i]&(1<<j)) {
				ct[j]++;b[j].insert(i);
			}
		}
	}
	//从高到低的贪心
	int as=0;
	for(int k=30;k>=0;k--) {
		if(ct[k]<m) continue;
		if(s.empty()) {
			for(auto i:b[k]) s.insert(i);
			as=(1<<k);
		} else {//交集>=m 
			if(_jiao(k)) {
				U(k);
				as+=(1<<k);
			}
		}
	}
	cout<<as;	
	
	return 0;
}
/*
显然从按位与的性质入手

4 2
3 15 12 12

5 3
31 3 1 15 7	

*/
