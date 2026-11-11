#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int w[N],cmp[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int cnt=2;
	int i=0;
	while(cin>>cmp[i]){
		i++;cnt++;
		if(i==n) break;	
	}
	int x_r,y_r;
	cin>>x_r>>y_r;
	int x_x,y_y;
	cin>>x_x>>y_y;
	
	for(int i=0;i<q;i++){
		cout<<cmp[i]*x_x/y_y+x_r-y_r<<endl;
	}
	
	return 0;
}
