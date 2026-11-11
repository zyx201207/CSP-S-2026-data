#include <bits/stdc++.h>
using namespace std;

int main() {
freopen("card.in", "w", stdin);
freopen("card.out", "r", stdout);
	int a,b,c[100001];
	cin>>a>>b;
	for(int i = 0;i<a;i++){
		cin>>c[i];
	}
	for(int i = 0;i<a;i++){
		if(c[i]!=c[i-1]){
			cout<<"1"<<" ";
		}
	}
}
