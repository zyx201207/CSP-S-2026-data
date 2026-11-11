#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a[510][510],b[510][510],r[100010],cs;
bool f=0;//,f[510][500010];
/*void xz(int wz){
	cs+=r[i];
} */
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<n;++i){
		cin>>k;
		for(int j=0;j<k;++j) cin>>a[i][j]>>b[i][j];
	}
	for(int i=0;i<q;++i) cin>>r[i];
	for(int i=1;i<n;++i) if(b[i]!=b[i-1]){
		f=1;
		break;
	}
	if(f){
		cout<<(r[0]-a[0][0])*(b[0][1]+b[abs(n-5)][5]);
	}else{
		//for(int i=0;i<q;++i) xz(i),cout<<cs*b[0],cs=0;
		cout<<(r[5]-cs)*b[0][0];
	}
	return 0;
} 
