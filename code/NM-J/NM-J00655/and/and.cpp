#include<bits/stdc++.h>
using namespace std;
long long b[10000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,c;
	cin>>a>>c;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	sort(b,b+a);
	cout<<b[a-c];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
