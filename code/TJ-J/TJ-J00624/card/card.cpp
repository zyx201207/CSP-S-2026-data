#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a;
	int b[300050] = {0};
	cin >> n >> m;
	int num = 0;
	for(int i=1;i<=n;i++){
		cin >>a;
		b[a] ++;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			cout << i <<" ";
		}
	}
	else if(n!=m){
		for(int i=1;i<=m;i++){
			cout << i <<" ";
		}
	}
	return 0;
}

