#include<bits/stdc++.h>
using namespace std;
int n,m,a,s[10000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		s[i]=a;
	};
	fclose(stdin);
	fclose(stdout);
	return 0;
}
