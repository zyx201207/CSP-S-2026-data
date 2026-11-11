#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],su[500010];
int ch(int x){
	int mi=1000000000000000000;
	for(int i=x;i<=n;i++){
		mi=min(mi,a[i]*x-(su[i]-su[i-x]));
	}
	return mi;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)su[i]=su[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mi=l+r+1>>1;
		if(ch(mi)<=m)l=mi;
		else r=mi-1;
	}
	cout<<l;
	return 0;
}
/*
14:30 ??? 14:30-00:30=14:00 clock isn`t true , it is before 30 min.
14:05 broke zip Oct31=Dec25? NO!!! Oct31==Dec25 YES!!! (=)!=(==)
14:15 AC T1
15:50 AC T2? O(nnn+mdd) 92-100 

QWQWQWQWQWQWQ

if(I uper 100th)I can continue class to NOIP

I bring 0 watch flybamboo is not true

18:11 dino 3300!!!

I`m csx .
I want Backspace  flybamboo`s wenzhang,because it is not ture.

Why I often hear  6-21 talk??
 
*/
