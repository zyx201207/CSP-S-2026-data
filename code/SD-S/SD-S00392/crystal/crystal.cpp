#include <bits/stdc++.h>
using namespace std;
//¿ªlonglong
bool mlest;

double tlest,tleed;

const long long N=5e5+10;

long long n,m,a[N],s[N];

void read(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
}

void init(){

}

bool check(long long mid,long long x){
	return (bool)(a[x]*(x-mid+1)-s[x]+s[mid-1]<=m);
}

long long fun(long long x){
	long long l=1,r=x,ans=x;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid,x)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
} 

void compute(){
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	long long ans=1;
	for(long long i=1;i<=n;i++){
		ans=max(ans,i-fun(i)+1);
	}
	cout<<ans;
}

void clear(){

}

void run(){
	read();
	init();
	compute();
	clear();
}

bool mleed;

void wa(){
	cerr<<"\n"<<tleed-tlest<<"ms\n"<<(&mleed-&mlest-1)/1024.0/1024.0<<"MB";
}

void fre(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	fre("crystal");
	tlest=clock();
	run();
	tleed=clock();
	return 0;
}

