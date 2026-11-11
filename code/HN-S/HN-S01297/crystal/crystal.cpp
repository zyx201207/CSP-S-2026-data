#include<bits/stdc++.h>
using namespace std;
struct P{
	int a,b;
} p[500001];
bool cmp1(P x,P y){
	return x.a < y.a;
}
bool cmp2(P x,P y){
	return x.b < y.b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,c = 0,k = 0;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;++i){
		scanf("%d",&p[i].a);
	}
	sort(a,a + n,cmp1);
	p[0].b = p[0].a;
	for(int = 1;i < n;++i){
		p[i].b = p[i + 1].a - p[i].a;
	}
	while(m--){
		sort(p,p + n,cmp2);
		if(p[k].b != 0){
			p[k].a++;
			p[k].b--;
		}else{
			k = ++c;
			k--;
		}
	}
	printf("%d",c);
	return 0;
}
