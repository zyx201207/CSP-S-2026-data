#include<bits/stdc++.h>
using namespace std;
#define int long long
struct X{
	int a;
	int c;
}x[200005];
bool cmp(const X p,const X q){
	return p.c<q.c;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,cnt=0,p,ans=0;
	cin>>n>>m; 
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>x[i].a;
		cnt+=x[i].a;
	}
	int maxx=0,minn=1e12;
	for(int i=0;i<n;i++) maxx=max(maxx,x[i].a);
	for(int i=0;i<n;i++) minn=min(minn,x[i].a);
	if(n*(maxx-minn)<1e9){
		for(p=minn;p<=maxx;p++){
			int anss=0;int m1=m;
			for(int i=0;i<n;i++){
				x[i].c=abs(x[i].a-p);
			}
			sort(x,x+n,cmp);
			for(int i=0;i<n;i++){
				if(m1-x[i].c>=0){
					m1-=x[i].c;
					anss++;
				}else{
					break;
				}
			} 
			ans=max(ans,anss);
		}
		cout<<ans;
		return 0;
	}
	p=cnt/n;
	double p2=cnt/n;
	if(p2-p>=0.5){
		p++;
	}
	for(int i=0;i<n;i++){
		x[i].c=abs(x[i].a-p);
	}
	sort(x,x+n,cmp);
	for(int i=0;i<n;i++){
		if(m-x[i].c>=0){
			m-=x[i].c;
			ans++;
		}else{
			break;
		}
	} 
	cout<<ans;
	return 0;
} 