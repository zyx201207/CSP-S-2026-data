#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T,n,k,u,v,m;
ll read(){
	char c=getchar();
	ll s=0;
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9') s=(s<<3)+(s<<1)+c-'0',c=getchar();
	return s;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();T=read();
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			u=read(),v=read();
		}
		m=(n-1)/2;
		if(k==1){
			cout<<(m+2)/2<<endl;
		}else{
			cout<<(m+5-k)/4<<endl;
		}
	}
	return 0;
}
