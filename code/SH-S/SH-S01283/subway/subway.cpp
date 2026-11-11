#include <bits/stdc++.h>
using namespace std;
int c,n/*xian*/,m/*zhan*/,d/*bei jin guo*/,q/*ji hua*/;
int w[500010]/*chu ting shi jian*/,a[501][500010]/*jin guo de zhan*/,t[5011][500010]/*ting-zhan shi jian*/;
int k[501]/*xian de zhan*/;
int x/*start*/,y/*end*/;
int zzz;
unsigned long long zt=184467440737095515;
unsigned long long mina(unsigned long long aaa,unsigned long long bbb){
	if(aaa>bbb){
		return bbb;
	}
	else{
		return aaa;
	}
}
void dfs(int l,int r,unsigned long long time,int line,int z){
	//cout<<l<<" "<<r<<" "<<time<<" "<<line<<" "<<z<<endl;
	if(l==r){
		//cout<<zt<<" "<<time+t[line][z]<<endl;
		zt=mina(zt,time+t[line][z]);
		//cout<<zt<<endl;
		return;
	}
	if(z+1<=k[line]) dfs(a[line][z+1],r,time,line,z+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==l && i!=line){
				//cout<<i<<" "<<j<<" "<<t[i][j]+t[line][z]<<endl;
				dfs(a[i][j+1],r,time+t[i][j]+t[line][z],i,j+1);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>zzz;
		k[i]=zzz;
		for(int j=1;j<=zzz;j++){
			cin>>a[i][j]>>t[i][j];
			//cout<<a[i][j]<<" "<<t[i][j]<<endl;
		}
	}
	for(int i=1;i<=q;i++){
		zt=184467440737095515;
		cin>>x>>y;
		//cout<<x<<" "<<y<<endl;
		for(int j=1;j<=n;j++){
			for(int o=1;o<=k[j];o++){
				if(a[j][o]==x){
					//cout<<j<<" "<<o<<" "<<t[j][o]<<endl;
					dfs(x,y,t[j][o],j,o);
				}
			}
		}
		cout<<zt+w[x]+w[y]<<endl;
	}
	return 0;
}
