#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m, a[N], b[N];

int main(){
	//*
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	//*/
	scanf("%d%d", &n, &m);
	for(int i = m; i >= 1; i--){
		scanf("%d", &a[i]);
		b[a[i]] = i;
	}
	for(int i = m; i >= 1; i--){
		printf("%d", b[i]);
	}
	return 0;
}


