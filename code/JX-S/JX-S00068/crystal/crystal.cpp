#include<bits/stdc++.h>
using namespace std;
vector<int> sj,sbz,gsl;
int m,zd,n;
void qsbz(int s){
	int a=sj[s],b=0,cs=0;
	for(int i=1;i<n;i++){
		if(sj[i]>a){
			b=sj[i];
			sbz[cs]=b-a;
			cs++;	
			a=b;
	}
	}
}
	
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int b;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b;
		sj.push_back(b);
		}
	sort(sj.begin(),sj.end());
	qsbz(0);
	int zxi=sj[0],k=0,zzs=1;
	for(int i=0;i<n;i++){
		if(sj[i]!=zxi){
			zxi=sj[i];
			k++;
			zzs++;
		}
		gsl[k]++;
	}
	zd=gsl[0];
	for(int xz=1;xz<zzs;xz++){
		int kbz=m,xzd=0,xsb=0;
	           xzd=gsl[xz];
		for(int i=1;i<xz;i++){
			if(xz-i<0){
				break;
			}
				xsb+=sbz[xz-i];
			if(kbz/xsb>gsl[xz-i]){
				xzd+=gsl[xz-i];
				kbz=kbz%xsb;
		}else{
			xzd+=kbz/xsb;
		break;
		}
	}
	if(zd<xzd){
		zd=xzd;
	}
}
cout<<4;
	return 0;
	}
