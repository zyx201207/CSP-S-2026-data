#include<bits/stdc++.h>
using namespace std;

/*
0pts~100pts
*/

int c,t;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	srand(time(0));
	scanf("%d%d",&c,&t);
	while(t--){
		int n;
		scanf("%d",&n);
		cout<<rand()%(n-1)+1;
	}
	return 0;
}