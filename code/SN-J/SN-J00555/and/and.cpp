#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,m,k[35],kk;
struct www{
	long long s,a;
}w[N];
vector<long long>t[N];
void updd(long long x,long long xx){
	for(long long i=0;i<=30;i++){
		if((x>>i)&1){
			k[i]++;
			t[i].push_back(xx);
		}
	}
}
bool cmp(www a,www b){
	return a.s>b.s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>w[i].a;
		updd(w[i].a,i);
	}
	for(long long i=30;i>=0;i--){
		if(k[i]<m)continue;
		for(long long x:t[i]){
			w[x].s+=(1<<i);
		}
	}
	sort(w+1,w+n+1,cmp);
	kk=w[1].a;
	for(long long i=2;i<=m;i++){
		kk=kk&w[i].a;
	}
	cout<<kk;
	return 0;
}
