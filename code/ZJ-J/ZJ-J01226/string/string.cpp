#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll num;
	char na;
}a[200005];
ll n;
ll pre[200005];
char find(ll x){
	for(ll i=1;i<=n;i++){
		if(x<=pre[i])return a[i].na;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int f=1;//判断是不是样例1718 
	ll len=0;
	for(ll i=1;i<=n;i++){
		ll x;char y;
		cin>>x>>y;
		len+=x;
		pre[i]=pre[i-1]+x;
		a[i].num=x;
		a[i].na=y;
		if(a[i].num>1)f=0; 
	} 
	ll sum=0;
	if(f){//特判样例1718 
		//就是说，每个字符只有一个
		for(ll i=1;i<=len/2;i++){
			if(a[i].na!=a[len-i+1].na)sum++;
		} 
		cout<<sum;
		return 0;
	}
	for(ll i=1;i<=len/2;i++){
		if(find(i)!=find(len-i+1))sum++;
	}
	cout<<sum;
	return 0;
}

