//西安辅轮中学 刘雨辰 SN-S00456 

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[2][500001],c=-1e12,d=0,e[500001],f=1e12,g=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	 
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		if(a[i]>0){
			b[0][a[i]]++;
		}
		else{
			b[1][-a[i]]++;
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]>=c){
				c=b[i][j];
				d=j;
			}
		}
	}
	if(m==0){
		cout<<c;
		return 0;
	}	

	for(int i=1;i<=n;i++){
		if(d-a[i]>0){
			e[i]=d-a[i];
		}
	}
	d=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(e[j]<f){
				f=e[j];
				d=j;
				g++;
				
			}		
		}	
		if(d==0){
			break;
		}
		if(m-f>0){
			m=m-f;
		}
		
		e[d]=0;
		f=0;
	}
	cout<<g;
	return 0;
}
