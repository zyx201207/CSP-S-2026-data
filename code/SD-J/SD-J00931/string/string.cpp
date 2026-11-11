#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,idl,idr;
ll L,posl,posr,ans;
struct Node{
	ll len;
	char c;
	ll stl,str;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		a[i].stl=a[i-1].str+1;
		a[i].str=a[i].stl+a[i].len-1;
		L+=a[i].len;
	}
	idl=1,idr=n;
	while(idl<idr){
		posl=posr+1;
		posr=min(a[idl].str,L-a[idr].stl+1);
		if(a[idl].c!=a[idr].c){
			ans+=posr-posl+1;
		}
		if(a[idl].str==posr){
			idl++;
		}
		if(a[idr].stl==L-posr+1){
			idr--;
		}
	}
	cout<<ans;
	return 0;
}
