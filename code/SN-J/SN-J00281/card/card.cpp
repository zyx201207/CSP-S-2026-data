#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,b[],a=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		cin>>b[i];
		if(i==b){
			continue;
			a++;
		}
}
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
