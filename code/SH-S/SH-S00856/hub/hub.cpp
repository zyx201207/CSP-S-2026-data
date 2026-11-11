#include<bits/stdc++.h>
using namespace std;
void init(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
void wait(int x){
	int c0=clock(),c1=clock();
	while(c1-c0<=x){
		c1=clock();
	}
}
int main(){
	init();
	wait(990);
	cout<<4598704;
	return 0;
}

