#include<bits/stdc++.h>
using namespace std;
bool fjx[50],fjy[50],fj[50];
const long long NN=2e5+7;
long long zhaodao[NN];
int feifu[NN];
long long n,m;
long long maxx;
long long andd(long long x,long long y){
	long long cnt1=0,cnt2=0,cnt=0;
	while(x!=0){
		fjx[++cnt1]=x%2;
		x/=2;
	}
	while(y!=0){
		fjy[++cnt2]=y%2;
		y/=2;
	}
	long long n1=0,n2=0; 
	while(n1!=cnt1&&n2!=cnt2){
		fj[++cnt]=(fjx[++n1] and fjy[++n2]);
	}
	long long sum=0;
	for(long long i=cnt;i>=1;i--){
		sum+=fj[i]*pow(2,i-1);
	}
	return sum;
}
long long andhe(){
	long long sum=zhaodao[1];
	for(int i=2;i<=m;i++){
		sum=andd(zhaodao[i],sum);
	}
	return sum;
}
long long quanpailie(int x,int y){
	if(y==m){
		return max(maxx,andhe());
	}
	if(x==n+1){
		return 0;
	}
	zhaodao[y+1]=feifu[x];
	quanpailie(x+1,y+1);
	quanpailie(x+1,y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>feifu[i];
	}
	cout<<quanpailie(1,0);
	return 0;
} 
