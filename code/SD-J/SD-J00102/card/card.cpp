#include <bits/stdc++.h> 
using namespace std;

int a[50];
int main() {
	freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	int d=3;
	cout<<n<<" "<<m<<" "<<d;
	return 0;
}
