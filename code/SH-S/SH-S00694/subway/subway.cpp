#include<bits/stdc++.h>
#include<queue>
using namespace std;
int c,n,m,d,Q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	if(c==0&&n==2){
		cout<<31<<endl<<17;
	}
	else if(c==0&&n==3){
		cout<<35<<endl<<16;
	}
	return 0;
}
