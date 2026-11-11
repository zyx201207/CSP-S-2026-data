#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
struct node{
	int m;
	int id;
}s[N];
struct node1{
	int a;
	int t;
	int id;
}p[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int k=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i].m;
		s[i].id++;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>p[i].a>>p[i].t;
			p[i].id=p[i].a;
		}
	}
	int x=0;
	int y=0;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
	}
	if(k<=2){
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
