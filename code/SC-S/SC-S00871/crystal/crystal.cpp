#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,yy=0,hh=0;
int a[500010]={0},c[10000010]={0};
int sstf(int x){
	int y=m,res=0;
	int b[100010]={0};
	for(int i=1;i<=n;++i){
		if(x>=a[i]){
			b[i]=x-a[i];
		}else{
			b[i]=10010;
		}
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;++i){
		if(y>=1){
			if(b[i]==0){
				res=res+1;
			}else if(b[i]>=1){
				y=y-1;
				b[i]=b[i]-1;
				if(b[i]==0){
					res=res+1;
				}else{
					i=i-1;
				}
			}	
		}else if(y==0){
			return res;
			break;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	yy=a[n];
	hh=a[1];
	for(int i=hh;i<=yy;++i){
		c[i]=sstf(i);
	}
	sort(c+hh,c+yy+1);
	cout<<c[yy];
	return 0;
} 