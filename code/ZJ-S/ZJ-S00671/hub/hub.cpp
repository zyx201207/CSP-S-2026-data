#include<bits/stdc++.h>
using namespace std;
long long rin(){
	long long ans = 0;
	char t = getchar();
	while(t<'0'||t>'9')t=getchar();
	while(t>='0'&&t<='9'){
		ans = ans*10+t-'0';t=getchar();
	}
	return ans;
}
void rout(long long d){
	if(d/10)rout(d/10);
	putchar('0'+d%10);
}
int c,t,n; 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = rin();t=rin();
	for(int i = 1;i<=t;i++){
		n = rin();int k;k=rin();
		for(int i = 1;i<n;i++){
			int u,v;u=rin();v=rin();
		}
		if(k==n){
			rout(0);putchar('\n');
		}
		if(k>=n/2+1){
			rout(1);putchar('\n');
		}
		int m = n/2+1-k;
		rout((m+2)/4+1);putchar('\n');
	}
	return 0;
}

