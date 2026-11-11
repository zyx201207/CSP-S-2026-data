#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,cnt,zq,pjs,dt,zh,zz=0;
struct node{
	long a,c;
}q[N];
long long f(int l,int r){
	for(int i=1;i<=r;i++){
		pjs+=q[i].a;
	}
	pjs=round(pjs/(n-dt));
	for(int i=1;i<=n;i++){
		q[i].c=abs(q[i].a-pjs);
		if(q[i].a>pjs){
			zh+=q[i].c;
		}
		if(q[i].a<pjs){
			zq+=q[i].c;
		}
	}
	return zq+zh-m;
}
int main(){
	freopen("crytal5.in","r",stdin);
	freopen("crytal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i].a;
		pjs+=q[i].a;
	}
	int l=1,r=q[n].a;
	while(f(l,r)>0){
		r--;
		if(q[n-dt].a>r)dt++;
	}
	cout<<n-dt;
	return 0;
}
