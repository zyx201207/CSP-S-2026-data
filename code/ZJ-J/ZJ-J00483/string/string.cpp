#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+1;
struct lts {
	int i;
	char c;
};
int n;
unsigned long long cnt;
vector<lts> V;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		lts c;
		cin>>c.i>>c.c;
		V.push_back(c);
	}
	int i=0,j=n-1;
	int ni=V[i].i,nj=V[j].i;
	while(i<j) {
		int mi=min(ni,nj);
		if(V[i].c!=V[j].c) {
			cnt+=mi;
		}
		mi=min(ni,nj);
		ni-=mi;
		nj-=mi;
		if(ni==0) {
			i++;
			ni=V[i].i;
		}
		if(nj==0) {
			j--;
			nj=V[j].i;
		}
	}
	cout<<cnt<<endl;
	return 0;
}