#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],lg[35];
bool cmp(long long a,long long b){
	return a>b;
}void make_lg(){
	for(int i=0;i<=35;++i)lg[i]=1;
	for(int i=1;i<=35;++i){
		lg[i]=lg[i-1]*2;
	}
	
}bool check(long long x){
	for(int i=0;i<=31;++i){
		if(lg[i]==x)return 1;//是2的整数幂 
	}return 0; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	make_lg();
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}sort(a+1,a+n+1,cmp);
	long long ans=0,st=0;
	for(int i=1;i<=n;++i){
		if(!check(a[i])){
			ans=a[i];
			st=i;
			break;
		}
	}
	for(int i=st+1;i<st+m;++i){
		if(check(a[i]))continue;
		ans=ans&a[i];
	}cout<<ans;
	return 0;
}/*

4 2
3 15 12 12


*/
