#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ma=-0x3f3f3f3f,zong=pow(2,30)-1,mm=-0x3f3f3f3f;
long long biao[35],c,z=pow(2,30)-1;
struct node{
	long long a,v;
}x[200005];
bool cmp(node q,node p){
	if(q.v!=p.v) return q.v>p.v;
	return q.a>p.a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=0;i<=30;i++){
		biao[i]=pow(2,i);
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i].a);
		while(x[i].a>=biao[c]){
			x[i].v=biao[c];
			c++;
			break;
		}
		ma=max(ma,x[i].a);
		zong=(zong&x[i].a);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		cout<<zong;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ma=max(ma,(x[i].a&x[j].a));
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			long long zz=pow(2,30)-1;
			for(int j=1;j<=n;j++){
				if(j!=i){
					zz=(zz&x[j].a);	
				}
			}
			mm=max(mm,zz);
		}
		cout<<mm;
		return 0;
	}
	sort(x+1,x+n+1,cmp);
	for(int i=1;i<=m;i++){
		z=(z&x[i].a);
	}
	cout<<z;
	return 0; 
}
