#include <bits/stdc++.h>
using namespace std;

long long A[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>A[i];
	}
	for(int i = 1;i <= n;i++){
		cout<<A[i]<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
