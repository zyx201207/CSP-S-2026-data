#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}l[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long h=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i].a>>l[i].c;
		h+=l[i].a;
	}
	int o=1,u=n;
	if(h%2){
		h=h/2+1;
	}else{
		h=h/2;
	}
	long long k=0;
	while(k<h){
		if(l[o].c==l[u].c){
			if(l[o].a>l[u].a){
				k+=l[u].a;
				l[o].a-=l[u].a;
				u--;
			}else if(l[o].a==l[u].a){
				k+=l[o].a;
				o++;u--;
			}else{
				k+=l[o].a;
				l[u].a-=l[o].a;
				o++;
			}
		}else{
			if(l[o].a>l[u].a){
				k+=l[u].a;
				l[o].a-=l[u].a;
				ans+=l[u].a;
				u--;
			}else if(l[o].a==l[u].a){
				k+=l[o].a;
				ans+=l[o].a;
				o++;u--;
			}else{
				k+=l[o].a;
				l[u].a-=l[o].a;
				ans+=l[o].a;
				o++;
			}
		}
	}
	cout<<ans;
	return 0;
}
