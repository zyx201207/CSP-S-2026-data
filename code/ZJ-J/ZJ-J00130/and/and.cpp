#include<bits/stdc++.h>
using namespace std;

int n,a[200001],m;
int c[21],lc,maxans=-1;//1-5,6,7,8-10
// cout<<(a & b);

void digui(int shangi){
	if(lc==m){
		int zhi=c[1];
		for(int i=2;i<=lc;i++)
			zhi=(zhi & c[i]);
		maxans=max(maxans,zhi);
		return;
	}	
	if(shangi>=n)
		return;
	for(int i=shangi+1;i<=n;i++){
		c[++lc]=a[i];
		digui(i);
		lc--;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20){
		digui(0);
		cout<<maxans;
		return 0;
	}else if(m==1){
		for(int i=1;i<=n;i++)
			maxans=max(maxans,a[i]);
		cout<<maxans;
		return 0;
	}else if(m==n){
		maxans=a[1];
		for(int i=2;i<=n;i++)
			maxans=(maxans & a[i]);
		cout<<maxans;
		return 0;
	}else if(n<=2000&&m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				maxans=max(maxans,(a[i] & a[j]));
		cout<<maxans;
		return 0;
	}else{
		cout<<0;
		return 0;
	}
}       