#include<iostream>
using namespace std;
#define int long long
const int N=2e5+5;
struct node{
	int len;
	string c;
}qu[N];
int n,l,r,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++)
 		cin>>qu[i].len>>qu[i].c;
 	r=n;
	for(l=1;l<r;l++){
		while(qu[r].len<qu[l].len&&l<r){
			if(qu[r].c!=qu[l].c) ans+=qu[r].len;
			qu[l].len-=qu[r].len;
			r--;
		}
		if(qu[r].c!=qu[l].c) ans+=qu[l].len;
		qu[r].len-=qu[l].len;
	}
	cout<<ans;
	return 0;
}
