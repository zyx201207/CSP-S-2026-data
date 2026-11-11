#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long n,m,g;
long long num[N];
void jyc(long long a,long long b) {
	stack<unsigned long long>st;
	stack<unsigned long long>ck;
	while(a!=0) {
		st.push(a%2);
		a/=2;
	}
	while(b!=0) {
		ck.push(b%2);
		b/=2;
	}
	long long k = min(st.size(),ck.size());
	for(int i = 0; i<k; i++) {
		if(st.top() == ck.top()&&st.top() == 1 && ck.top() == 1) {
			int h = 1;
			for(int j = 1; j<=i; j++) {
				h*=2;
			}
			g+=h;
			st.pop();
			ck.pop();
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0; i<n; i++) {
		cin>>num[i];
	}
	long long maxn = 0;
	for(int i = 0; i<n-1; i++) {
		for(int j = i+1; j<n; j++) {
			g = 0;
			jyc(num[i],num[j]);
			maxn = max(g,maxn);
		}
	}
	cout<<maxn;
	return 0;
}

