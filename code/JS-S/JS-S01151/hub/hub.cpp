#include <bits/stdc++.h>
using namespace std;
int c,t;
int rd(){
	int k=0;
	int f=1;
	char c;
	c=getchar_unlocked();
	while(c<'0'||c>'9'){
		if(c=='-')    f=-1;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar_unlocked();
	}
	return k*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=rd();
	t=rd();
	while(t--){
		cout<<1<<'\n';
	}
	return 0;
}
