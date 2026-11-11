#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500006];
int cmd(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long zd=-1;
	long long dx=0;
	long long uiop=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		dx+=a[i];
	}
	sort(a+1,a+n+1,cmd);
	long long dx1=a[1]+a[n];
	dx1*=n;
	dx1/=2;
	long long iji=a[1]-a[2];
	for(int i=2;i<=n;i++){
		long long hjkl=a[i]-a[i-1];
		if(hjkl==iji){
			uiop+=hjkl;
		}
	}
	int lsn=n-1;
	int n11=uiop/lsn;
	if(dx1==dx&&n11==iji){
//		exit(0);
		long long jsy=uiop/iji;
		long long ccc=0;
		long long iii=iji;
		long long jsq=0;
		while(ccc>jsy){
			jsq++;
			ccc+=iii;
			iii+=iji;
		}
		jsq--;
		cout<<jsq;
	}
	else{
	//	cout<<a[n]-a[1];
	//	cout<<dx<<endl;
	//	for(int i=1;i<=n;i++){
	//		cout<<a[i]<<" ";
	//	}
	//	for(int i=1;i<=n;i++){
	//		cout<<a[i];
	//	}
	//	long long cz=0;
		for(long long ss=1;ss<=n;ss++){
			long long lsm=m,gunmu=1;
	//		cout<<ss<<" ";
	//		cout<<lsm;
			for(long long i=ss+1;i<=n;i++){
				long long ls;
				ls=a[ss]-a[i];
				if(lsm>=ls){
	//				cout<<i<<endl;
					lsm-=ls;
					gunmu++;
				}
				if(ss==1){
	//				cz+=ls[i];
				}
			}
			if(gunmu>zd){
				zd=gunmu;
			}
	//		cout<<gunmu<<endl;
		}
	//	cout<<cz.size()<<endl;
		cout<<zd;
	}
	return 0;
} 
