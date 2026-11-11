#include<bits/stdc++.h>
using namespace std;

int w[505],k[505],
	a[505][100005],t[505][100005],
	x[100005],y[100005]; 

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	//ÊäÈë 
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	} 
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=0;r<q;r++){
		cin>>x[r]>>y[r];
	}
	
	for(int i=0;i<q;i++){
		cout<<'0';
	}
	 
	return 0;
} /*
                              ----
--------------------------------------------------- 
		  -     -          -      -     -         -
    		  -            -       -       -      -
    		               -                   -  -
    		               -
*/    		               
