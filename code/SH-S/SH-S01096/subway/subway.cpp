#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[100000009];
long long k[10005],a[10005],t[10005],x[10005],y[10005];
struct station{
	long long u,v,t;
};station s[100000009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>s[j].t;
		}
	}
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	cout<<
}
