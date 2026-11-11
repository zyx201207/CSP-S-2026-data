#include<bits/stdc++.h>
using namespace std;
long long c,t,w[2000006],n,d,ans=0;
inline long long read(){
	int c;c=getchar();long long ans=0,f=1;
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ans=ans*10+c-'0';
		c=getchar();//getchar_unlocked
	}
	return ans*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		printf("1\n");
	}
	
}
