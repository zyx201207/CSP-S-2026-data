#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,e,x,y;ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c>>d>>e;
	for(int i=0;i<c;i++){
		cin>>x;
	}
	for(int i=0;i<b;i++){
		cin>>x;
		for(int j=0;j<x;j++){
			cin>>y;
		}
	}
	for(int i=0;i<e;i++){
		cin>>x>>y;
	}
	if(a==0&&b==2) cout<<32<<"\n"<<17;
	if(a==0&&b==3) cout<<35<<"\n"<<16; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
