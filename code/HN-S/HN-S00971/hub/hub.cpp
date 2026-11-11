#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5e6+5;
const ll M=1e12;
int read(){
	int w=1,x=0; char s=getchar();
	while(s<'0'||s>'9'){
		if(s=='-') w=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+s-'0';
		s=getchar();
	}
	return x*w;
}
int n,t,c,k;
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(); t=read();
	while(t--){
		n=read(); k=read();
		int x,y;
		for(int i=1;i<n;i++){
			x=read(); y=read();
		}
		if(k<=(n+1)/2) cout<<1<<'\n';
		else cout<<2<<'\n';
	}
	return 0;
}
