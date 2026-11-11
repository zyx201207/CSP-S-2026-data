#include<bits/stdc++.h>
#include<map>
using namespace std;
long long n,ans,tot,v,u;
struct node{
	long long l,r;
	char y;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		int b;
		cin>>b>>a[i].y;
		a[i].l = a[i-1].r+1;
		a[i].r = a[i].l+b;
	}
	v = 1,u = n;
	while(v <= u){
		int l1 = a[v].r - a[v].l,l2 = a[u].r - a[u].l;
		if(v == u){
			ans += l1/2;
			break;
		}
		if(a[v].y == a[u].y){
			ans += min(l1,l2);
			if(l1 == l2){
				v++;u--;
				continue;
			}
			if(l1 < l2){
				a[u].l+= l1;
				v++;
			}else{
				a[v].l +=l2;
				u--;
			}
		}else{
			if(l1 == l2){
				v++;u--;
				continue;
			}
			if(l1>l2){
				a[v].l +=l2;
				u--;
			}else{
				a[u].l += l1;
				v++;	
			}
		}
	}
	cout<<(tot-ans*2)/2;
    return 0;
}
