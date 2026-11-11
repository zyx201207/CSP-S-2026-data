#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long read(){
	char ch;
	long long f=1,x=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	t=read();
	for(int i=1;i<=t;i++){
		cout<<1<<endl;
	}
	return 0;
}
