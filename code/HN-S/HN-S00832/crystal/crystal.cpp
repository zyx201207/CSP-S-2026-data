#include<iostream>
using namespace std;
long long m,n,a[500010],x1,aa[500010],h[500010],ans=0;
void it(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x1+=a[i];
	}
}
void jie(){
	for(int i=0;i<=n;i++){
		h[i]=0;
	}
}
void px(long long x){
	int xa,j1=0;
	for(int i=1;i<=n;i++){
		xa=1000000000;
		for(int j=1;j<=n;j++){
			if(xa>=a[x]-a[j]&&h[j]==0&&a[x]-a[j]>0){
				xa=a[x]-a[j];
				aa[i]=a[j];
				j1=j;
			}
			if(a[x]-a[j]<0&&h[j]==0){
				if(xa>=a[j]-a[x]&&h[j]==0){
					xa=a[j]-a[x];
					aa[i]=a[j];
					j1=j;
				}
			}
			if(a[x]-a[j]==0&&h[j]==0){
				ans++;
				h[j]=1;
			}
		}
		h[j1]=1;
	}
}
void w(){
	long long x=x1/n,mi,xi=0,ii=1;
	mi=x-a[1];
	for(int i=2;i<=n;i++){
		if(mi>x-a[i]&&x-a[i]>=0){
			ii=i;
			xi=a[i];
			mi=x-a[i];
		}
		if(x-a[i]<0){
			if(mi>a[i]-x){
				ii=i;
				xi=a[i];
				mi=a[i]-x;
			}
		}
	}
	px(ii);
	for(int i=1;i<=n;i++){
		if(m<0){
			cout<<ans-1;
			return;
		}
		if(m==0){
			cout<<ans;
			return;
		}
		if(xi-aa[i]>0){
			m-=xi-aa[i];
			ans++;
		}
		else{
			m+=xi-aa[i];
			ans++;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	it();
	w();
	return 0;
}
