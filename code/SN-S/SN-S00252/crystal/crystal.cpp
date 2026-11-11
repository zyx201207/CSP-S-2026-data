#include<bits/stdc++.h>
using namespace std; 
struct node{
	int number;
	int cha;
}a[100010];
bool cmp(node x,node y){
	return x.number<=y.number;
}
bool cmp1(node x,node y){
	return x.cha <=y.cha;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].number;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++){
		a[i].cha=abs(a[i+1].number-a[i].number);
	}
	a[n].cha=0;
	sort(a+1,a+n+1,cmp1); 
	int ans=0,qwer=0;
	for(int i=1;i<=n;i++){
		if(m<=0){
			cout<<ans-1;
			return 0;
		}
		qwer+=a[i].cha;
		m-=qwer;
		ans++;
	}
	return 0;
}
