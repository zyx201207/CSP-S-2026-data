#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;

struct And{
	long long num,id;
}a[200005];

long long Count(long long x){
	long long t=1,cnt=0,tx=x;
	while(1){
		if(t>ceil(x/2)) break;
		t*=2;
	}
	while(tx>0){
		if(tx<t) continue;
		tx-=t;
		cnt++;
		t/=2;
	}
	return cnt;
}

bool cmp(And x,And y){
	if(x.id!=y.id)return x.id>y.id;
	else return x.num>y.num;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].num;
	for(int i=1;i<=n;i++) a[i].id=Count(a[i].num);
	/*for(int i=1;i<=n;i++) cout<<a[i].id<<endl;
	cout<<Count(15);*/
	sort(a+1,a+n+1,cmp);
	//for(int i=1;i<=n;i++) cout<<a[i].num<<endl;
	ans=a[1].num;
	for(int i=2;i<=m;i++) ans&=a[i].num;
	cout<<ans;
	return 0;
}
