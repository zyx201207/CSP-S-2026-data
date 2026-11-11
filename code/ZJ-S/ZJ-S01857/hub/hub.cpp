#include<bits/stdc++.h>
using namespace std;
int x,c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++){
		srand(time(0));
		x=rand()*rand()%(i*i*i%13)+1;
		cout<<x<<"\n";
	}
	return 0;
}