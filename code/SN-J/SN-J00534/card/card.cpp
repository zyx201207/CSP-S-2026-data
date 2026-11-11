#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,m,a[50050],t[50050];
int main(int argc, char** argv) {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	} 
	for(int i=1;i<=m;i++){
		if(t[i]==1) cout<<n+i-m<<" ";
		else cout<<t[i]<<" ";
	}
	return 0;
}
