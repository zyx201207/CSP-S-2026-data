#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int a,b,c,d,e[10000];
	cin>>a>>b;
	for(int i=1;i<=b;i++){
		cin>>c>>d;
		for(int j=1;j<c;j++){
			cin>>e[j];
		}
		cout<<e[c/2]/e[1];
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
