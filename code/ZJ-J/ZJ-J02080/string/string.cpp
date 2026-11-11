#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l,r;
	char c;
}a[200005];
long long len;
long long ans;
int kl=1,kr,tq;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i].l=a[i-1].r+1;
		a[i].r=a[i].l+x-1;
		cin>>a[i].c;
		len+=x;
	}
	kr=n;
    tq=0;
	while(kl<=kr){
		long long z=a[kl].r;
		long long y=a[kr].l;
		long long tx;
		tx=min(z,len-y+1);
		char p=a[kl].c;
		char q=a[kr].c;
		if(p!=q){
			ans+=(tx-tq);
		}
		if(z<len-y+1){
			kl++;
		}else if(z==len-y+1){
			kl++;
			kr--;
		}else{
			kr--;
		}
		tq=tx;
	}
	cout<<ans;
	return 0;
}
