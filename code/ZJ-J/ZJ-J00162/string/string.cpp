#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;

struct S{
	ll x;
	char c;
}a[200010],b[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		if(i!=1){
			if(a[i].c==a[i-1].c){
				a[i].x+=a[i-1].x;
				a[i-1].x=0;
			}
		}
	}
	int len=1;
	for(int i=1;i<=n;i++){
		if(a[i].x!=0){
			b[len].x=a[i].x;
			b[len++].c=a[i].c;
		}
	}
//	for(int i=1;i<=len;i++){
//		cout<<b[i].x<<' '<<b[i].c<<'\n';
//	}
	len--;
	ll ans=0;
	int v=len; 
	for(int i=1;i<=len;i++){
		ll t=0;
		ll d=b[i].x;
		while(d&&v&&i<=v){
//			cout<<i<<' '<<d<<' '<<b[v].x<<'\n';
			if(b[i].c==b[v].c){
				if(d>=b[v].x){
					d-=b[v].x;
					v--;
				}
				else{
					b[v].x-=d;
					break;
				}
			}
			else{
				if(d>=b[v].x){
					t+=b[v].x;
					d-=b[v].x;
					v--;
				}
				else{
					t+=d;
					b[v].x-=d;
					break;
				}
			}
		}
		ans+=t;
//		}
		
//		cout<<t<<' '<<b[len+1-i].x<<' '<<b[i].x<<'\n';
	}
	cout<<ans;
//	*/
}
/*
5
2 a
3 a
2 a
3 b
2 a
*/ 

