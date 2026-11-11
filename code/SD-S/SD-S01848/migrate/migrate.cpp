#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		int n=read(),d=read();
		long long x[200006];
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		if(n==2||n==3||n==1){
			cout<<"0"<<endl;
			continue;
		}
		int dengcha=1;
		long long kk=x[n]-x[n-1];
		for(int i=n-1;i>=2;i--){
			if(kk!=x[i]-x[i-1]) dengcha=0;
		}
		if(dengcha==1){
			if(d<kk){
				cout<<0<<endl;
				continue;
			}
			else{
				cout<<(n-1)/2<<endl;
				
			}
		}
	}
	return 0;
}
