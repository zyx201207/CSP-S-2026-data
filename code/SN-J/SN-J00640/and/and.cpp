// 李思齐 陕西省西安爱知中学 SN-J00640 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[100500]={},cnt=0,ity=0,m,amxn=0,maxn=0,p=3,f=15;
void nuble(ll ids,ll num,ll cnt){
	//go
	if(cnt==m){
		amxn=max(amxn,num);
		return;
	}
	if(ids>n)return;
	//do
	nuble(ids+1,num,cnt);
	if(cnt==0)nuble(ids+1,a[ids],cnt+1);
	else nuble(ids+1,a[ids]&num,cnt+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=20){
		nuble(1,0,0);
		//p=p&f;
		cout<<amxn;
	}else if(m==1)cout<<maxn;
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				amxn=max(amxn,a[i]&a[j]);
			}
		}
		cout<<amxn;
	}else if(m==n){
		amxn=a[1];
		for(int i=2;i<=n;i++){
			amxn=amxn&a[i];
		}
		cout<<amxn;
	}else{
		amxn=a[1];
		for(int i=2;i<=n;i++){
			amxn=amxn&a[i];
		}
		amxn=amxn^a[1];
		for(int i=2;i<=n;i++){
			amxn=max(amxn,amxn^a[i]);
		}
		cout<<amxn;
	}
	return 0;
}
/*
5 3
31 3 1         15 7
*/
