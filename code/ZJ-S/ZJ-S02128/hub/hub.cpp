#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long read(){
	long long nov=1,dat=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') nov=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		dat=(dat<<3)+(dat<<1)+(c&15);
		c=getchar();
	}
	return nov*dat;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	return 0;
}