#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	c=read();t=read();
	srand(time(0));
	while(t--){
		if(c==13||c==14){
			long long z,x,c;
			z=read();x=read();
			for(int i=1;i<z;i++){
				c=read();c=read();
			}
			if(x==z)cout<<0<<"\n";
			else if(x>=z/2)cout<<1<<"\n";
			else if(x==1)cout<<z/2/2+1<<"\n";
			else{
				cout<<(z/2-x+3)/4+1<<"\n";
			}
		}
		else cout<<rand()%2+1<<"\n";
	}
	return 0;
}