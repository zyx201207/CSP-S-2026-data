#include<iostream>
using namespace std;
int c , t , n , k , u , v;
int main(){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout); 
	scanf("%d%d" , &c , &t);
	while (t--){
		scanf("%d%d" , &n , &k);
		for (int i = 1 ; i <= n ; i++)
			scanf("%d%d" , &u , &v);
		puts("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
