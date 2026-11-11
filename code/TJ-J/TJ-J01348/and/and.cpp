#include<bits/stdc++.h>
using namespace std;
long long l[200005];
bool cmp2(long long a,long long b){
	return a>b;
}
bool cmp(long long a,long long b){
	long long wei1=0,wei2=0;
	while(a>0){
		wei1+=(a%2);
		a/=2;
	}
	while(b>0){
		wei2+=(b%2);
		b/=2;
	}
	if(wei1==wei2)return a>b;
	else return wei1>wei2;
}
int main(){
	ifstream ci("and.in");
	ofstream co("and.out");
	long long n,m;
	ci>>n>>m;
	for(int i=1;i<=n;i++)ci>>l[i];
	sort(l+1,l+1+n,cmp2);
	sort(l+1,l+n+1,cmp);
	long long k=l[1];
	for(int i=2;i<=m;i++)k&=l[i];
	co<<k<<'\n';
	//for(int i=1;i<=n;i++)co<<l[i]<<' ';
	return 0;
}
