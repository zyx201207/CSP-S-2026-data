#include<bits/stdc++.h>
using namespace std;
int op,t;
inline int read(){
	long long f=1,x=0;
	char c=getchar();
	while(!(c>='0'&&c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n%2==1){
			cout<<1<<"\n";
		}else{
			cout<<2<<"\n";
		}
	}
	return 0;
}
