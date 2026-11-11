#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long aa[N];
bool cmp(long long oo,long long pp){
	return oo>pp;
}
int main(){
	freopen("and.in","a",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>aa[i];
	if(m==1){
		long long ll=0;
		for(int i=0;i<n;i++)ll=max(ll,aa[i]);
		cout<<ll;
	}
	else if(m==2){
		sort(aa,aa+n,cmp);
		cout<<(aa[0]&aa[1]);
	}
	else if(m==n){
		long long ll=aa[0];
		for(int i=1;i<n;i++){
			ll=ll&aa[i];
		}
		cout<<ll;
	}else {
		long long ll=aa[0];
		sort(aa,aa+n,cmp);
		for(int i=1;i<m;i++){
			ll=ll&aa[i];
		}
		cout<<ll;
	}
	return 0;
}
