#include<bits/stdc++.h>
using namespace std;
struct s{int w[10000],k,a[10000],t[10000];
} b[1000];
bool cmp(s.x,s.y){
	if(w.x!=w.y)
	return w.x<w.y;
	if(a.x!=a.y)
	return a.x<a.y;
	if(t.x!=t.y)
	return t.x<t.y;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<m;i++) cin>>w[i];
	cin>>k;
    for(int i=1;i<n;i++) cin>>a[i]>>t[i];
	for(int i=1;i<m;i++) cin>>x>>y;
	for(int i=1;i<m;i++){
		min(b,b+1000,cmp);
		cout<<b[m];
	}
	return 0;
}