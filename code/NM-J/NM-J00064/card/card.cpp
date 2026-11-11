#include<bits\stdc++.h>
using namespace std;
long long n,m,x,a[800010],b[300010],c[800010],d[300010];
long long check(int f,int _f){
	int r;
	for(int i=_f;i<=n;i++){
		if(c[i]==f){
			r=i;
			break;
		}
	}
	return r;
}
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[j]=a[j];
			b[j]=0;
		}
		for(int j=i;j<=n;j++){
		b[a[j]]++;
		if(b[a[j]]>=2){
			x=i;
			for(int k=check(a[j],x);k<j;k++){
				c[k]=0;
			}
			b[a[j]]=1;
		}
		}
		for(int j=i;j<=n;j++){
		d[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" "; 
	}
	return 0;
}
