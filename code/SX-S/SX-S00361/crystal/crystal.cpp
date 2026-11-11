#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct A{
	ll num;
	ll flag;
	ll l;
	bool f;
}a[500005],b[500005];


bool cmp(A x,A y){
	return x.num<y.num;
}
bool cmp2(A x,A y){
	return x.flag<y.flag;
}
int main(){
    ll n,ans,m,cost=0,cnt=1,tot=1;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crestal.out","w",stdout);
	cin>>n>>m;
	ll re=m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;


	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++){
		a[i].flag=a[i+1].num;
		a[i].l=a[i].flag-a[i].num;

	}
	sort(b+1,b+n+1,cmp2);
    for(ll i=1;i<n;i++){


            re-=a[i].l*cnt;



            a[i].num=a[i].flag;
            a[i].flag=a[i+1].flag;
            a[i].l=a[i+1].l;
            if(!a[i].f){
                cnt++;
            }
            a[i].f=true;


            if(re<0){
                tot=max(tot,cnt)-1;
                cnt=1;
                re=m;
                cost=0;
            }




    }



	cout<<tot;


	return 0;
}
