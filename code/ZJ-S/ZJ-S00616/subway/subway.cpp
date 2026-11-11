#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,sum;
long long a[500010],k[510];
struct S{
	int ztid;
	int zttime;
}b[500010];
void f(int x){
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>b[j].ztid>>b[j].zttime;
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		sum=a[l]+a[r];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(b[j].ztid==l){
					f(i);
				}
			}
		}
	}
	return 0;
}