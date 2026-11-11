#include <bits/stdc++.h>
using namespace std;
//¿ªlonglong
bool mlest;

double tlest,tleed;

const long long N=2e6+10;

long long n,x[N],d;

void read() {
	cin>>n>>d;
	for(long long i=1; i<=n; i++) {
		cin>>x[i];
	}
}

void init() {

}

bool check(long long a,long long b,long long c) {
	if(x[b-1]-x[a]<=d&&x[c]-x[b-1]<=d&&(x[b-2]-x[a]>d||x[c]-x[b-2]>d)&&(x[b+1]-x[a]>d||x[c]-x[b+1]>d)) return 1;
	if(x[b+1]-x[a]<=d&&x[c]-x[b+1]<=d&&(x[b-1]-x[a]>d||x[c]-x[b-1]>d)&&(x[b+2]-x[a]>d||x[c]-x[b+2]>d)) return 1;
	return 0;
}

void compute() {
	long long ans=0;
	for(int i=1; i<=n; i++) {
		for(long long j=i+2,k=i+1,p=i; j<=n; j++) {
			if(x[j]-x[p]<=d) continue;
			if(x[j]-x[k]>d) p=k;
			while(x[k+1]-x[p]<=d) k++;
			if(check(p,k,j)) {
				long long l=1,r=1;
				while(x[p]-x[p-1]==d) {
					l++;
					p--;
				}
				while(x[j+1]-x[j]==d) {
					r++;
					j++;
				}
				ans+=l*r;
			}
		}
	}
	cout<<ans<<'\n';
}

void clear() {

}

void run() {
	read();
	init();
	compute();
	clear();
}

bool mleed;

void wa() {
	cerr<<"\n"<<tleed-tlest<<"ms\n"<<(&mleed-&mlest-1)/1024.0/1024.0<<"MB";
}

void fre(string s) {
	freopen((s+".in").c_str(),"r",stdin);
//	freopen((s+".out").c_str(),"w",stdout);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	fre("migrate");
	tlest=clock();
	int c,t;
	cin>>c>>t;
	while(t--)
		run();
	tleed=clock();
//	wa();
	return 0;
}

