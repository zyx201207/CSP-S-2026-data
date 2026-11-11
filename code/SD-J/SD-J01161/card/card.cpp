#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],e[500005];
struct nm{
	int k,s; //k 位置 s次数
};
struct mm{
	int q,p,qp; //q 有没有出现 p 牌面出现次数 qp 牌本身 
}f[500005];
int cmp(mm x,mm y){
	if(x.p==y.p) return x.qp<y.qp;
	else return x.p>y.p;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1 ; i<=n ; i++){
	    cin>>a[i];
	    f[i].qp=a[i];
	    f[i].p=1;
	}
	sort(f+1,f+m+1,cmp);
	for(int i=1 ; i<=n ; i++){
		int y[300005]={0},p=1;
		nm b[300005]={0};
		for(int j=i ; j<=n ; j++){
			b[a[j]].s++;
			if(b[a[j]].s!=1){
				for(int x=b[a[j]].k ; x<=j ; x++){
					y[x]=0;
				}
				p=b[a[j]].k;
				y[p]=a[j];
				p++;
				b[a[j]].k=j;
				continue;
			}
			y[p]=a[j];
			p++;
			b[a[j]].k=j;
		}
		for(int j=1 ; j<p ; j++){
			f[y[j]].q++;
		}
	}
	for(int i=1 ; i<=n  ;i++){
		cout<<f[i].q<<" ";
	}
	return 0;
} 
