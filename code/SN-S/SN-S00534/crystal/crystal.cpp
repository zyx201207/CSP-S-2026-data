//zhangzhitong xianshidibahsijiuzhongxue SN-S00534
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+5;
struct node{
	ll f,c;
}a[N];
int n,cnt=1,ans;
ll m,mid;
bool cmp(node x,node y){
	return x.c<y.c;
}
bool cmp1(node x,node y ){
	return x.f<y.f;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].f;
	}
	sort(a+1,a+n+1,cmp1);
	mid=a[n+1>>1].f;
	for(int i=1;i<=n;i++){
		a[i].c=abs(a[i].f-mid);
		
	}
	sort(a+1,a+n+1,cmp);
	
	while(1){
		if(m-a[cnt].c<=0){
			break;
		}
		m-=a[cnt].c;
		//cout<<m<<" ";
		cnt++;
		
	}
	cout<<cnt-1;
	return 0;
}

