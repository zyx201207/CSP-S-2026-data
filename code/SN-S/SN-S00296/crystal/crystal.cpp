#include <bits/stdc++.h>
using namespace std;
const int N=1e4+77;
long long aa[N];
long long n,m,mi,cnt,ma;
bool cmp(long long xx,long long yy){
	return xx>=yy;
}
int main(){
	freopen("crystal.in","a",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	mi=(n+1)/2;
	for(int i=1;i<=n;i++)cin>>aa[i];
	ma=aa[mi];
	while(aa[mi]==aa[mi+1]){
		mi++;
	}
	sort(aa+1,aa+mi+1,cmp);
	for(long long i=1;i<=mi;i++){
		long long uu=ma-aa[i];
		if((m-uu)>=0){
			m-=uu;
			cnt++;
		}else break;
	}
	cout<<cnt;
	return 0;
}
