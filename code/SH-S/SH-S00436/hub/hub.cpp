#include<bits/stdc++.h>
using namespace std;
void file(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
int c,T;
int main(){
	file();
	srand(time(0));
	scanf("%d%d",&c,&T);
	while(T--)printf("%d\n",(rand())%50+1);
	return 0;
}
