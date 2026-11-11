#include<iostream>
using namespace std;
const int N=1e5+10;
int n,m,ans,sum,bns=1;
int a[N],b[N],c[N],d[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int y=a[i],t=0;
		while(y!=0){
			b[++t]=y%2;
			y/=2;
		}
		for(int j=1;j<=t;j++){
			if(b[j]==1) sum++;
		}
		c[i]=sum;
		sum=0;
		for(int j=1;j<=t;j++){
			b[j]=0;
		}
	}
	//for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	int x=0,id;
	while(ans<=m){
		for(int i=1;i<=n;i++){
			int max_=-10000;
			if(c[i]>max_){
				max_=c[i];
				id=i;
			}
		}
		c[id]=-10001;
		d[++x]=a[id];
		ans++;
	}
	for(int i=1;i<=m;i++){
		bns=bns&d[i];
	}
	cout<<bns;
	return 0;
}

