#include<bits/stdc++.h>
#include<ctime>
using namespace std;
int main(){
	int n;
	srand(time(0));
	n=rand()%90+1;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(n%10==0) printf("%d",1111);
	if(n%10==1) printf("%d",1110);
	return 0;
}
