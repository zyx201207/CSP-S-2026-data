#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
long long c, n, m, d, q;
cin>>c>>n>>m>>d>>q;
long long w[m],s[n];
for(int i=0;i<m;i++){
	cin>>w[i];
	}
for(int i=0;i<n;i++){
	cin>>s[i];
	long long a[n][s[i]] , t[n] [s[i]] , x[p] , y[p];
for(int j=0;j<s[i];j++){
	cin >> a[i][j] >> t[i][j];
}
	}
    for(int i = 0;i < p; i++){
    cin>>x[i]>>y[i];
    long long z=10000000;
    for(int h=0;h<n;h++){
    long long g=w [x[i]] + w[y[i]];
    int r,e;
    int x=0,y=0;
    for(int j=0;j<s[h];j++){
	if(a[h] [j]=x[i]){
    x++;
    r=j;
		}
	if( a[h] [j] =y[i]){
	y++;	
	e=j;
		}	
		}
	if(x==1||y==1){
	g = g+t[h] [r]+t[h][e];
		}
    }	
	if(g < z){
	z=g;	
		}
	
		}
	cout<<z;
return 0;
}
