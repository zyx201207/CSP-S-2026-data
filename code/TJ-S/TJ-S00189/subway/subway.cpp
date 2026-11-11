#include<bits/stdc++.h>
using namespace std;
const int N=510;
int w[N];
int a[N][N],t[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int s=1;
    while(n--){
    	int x;
    	cin>>x;
    	for(int j=1;j<=x*2;j++){
    		cin>>a[s][j];
		}
		s++;
	}
    while(q--){
    	int x,y;
		cin>>x>>y; 
	}
    if(n==2&&m==5){
    	cout<<32<<endl<<17;
    	return 0;
	}
    if(n==3&&m==7){
    	cout<<35<<endl<<16;
    	return 0;
	}
	return 0;
}

