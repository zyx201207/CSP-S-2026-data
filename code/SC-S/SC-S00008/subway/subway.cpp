#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long k;
long long t[100000005];
long long sum = 0;
long long u= 0;
struct node{
	long long t;
	long long zhan;
}a[10000005];
struct qsd{
	long long t;
	long long zhan;
}b[10000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i = 1;i<=m;i++){
		cin>>t[i];
	}
	for(long long i = 1;i<=n;i++){
		cin>>k;
		if(i == 1){
			u = k;
			for(long long y = 1;y<=k;y++){
				cin>>b[i].zhan>>b[i].t;
			}
		}
		for(long long j = 1;j<=k;j++){
			cin>>a[i].zhan>>a[i].t;
		}
	}
	while(q--){
		long long s,e;
		cin>>s>>e;
		sum+=t[s];
		for(int i = 1;i<=u;i++){
			if(b[i].zhan == e){
				cout<<sum+t[e];
				return 0;
			}else{
				sum+=b[i].t;
			}
		}
	}
	return 0;
}