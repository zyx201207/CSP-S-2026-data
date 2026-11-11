#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
struct node{
	int u;
	int v;
}a[N];
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	int n,k;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		cin>>a[i].u>>a[i].v;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
