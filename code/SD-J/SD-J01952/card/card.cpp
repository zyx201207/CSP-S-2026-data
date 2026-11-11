#include <bits/stdc++.h>
using namespace std;
long long N[500010],M[500010],A[500010],sl[500010],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,i;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a;
		A[i]=a; 
		M[a]=N[a];
		N[a]=i;
	}
	sl[a]=n;
	for(i=1;i<=n;i++)cout<<i<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
