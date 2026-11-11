#include<bits/stdc++.h>
using namespace std;
int main(){
	int s[100005],h[100005];
	int b[505][500005];
	int c[505][500005];
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
int c, n, m, d, q;
cin>>c>>n>>m>>d>>q;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数。
int a[n];
for(int i=0;i<m;i++){
	cin>>a[i];
	}
	for(int i=0;i<n;i++){
	    int t;
		cin>>t;
		for(int j=0;j<t;j++){
		cin>>b[i][j]>>c[i][j];	
			}
		}
		int ans=0;
	for(int i=0;i<q;i++){
		cin>>s[i]>>h[i];
		
}
		cout<<s[i]+h[i]*2;
return 0;
}
/*danggouchengdengchashulieshi,
 * /
