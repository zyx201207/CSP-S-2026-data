#include<bits/stdc++.h>
using namespace std;
int b[550000],c[330000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[550000],n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=n;
	for(int i=1;i<=n;i++){
		int id=1;
		
		for(int j=i;j<=n;j++){
		b[id]=a[j];
			bool op=false;
			int d;
			for(int k=1;k<=j;k++){
				if(b[k]==a[j]){
					op=true;
					d=k;
				}
			}
			if(op){
				for(int l=d;l<=j;l++){
					b[l]=0;
				}
				b[d]=a[j];
			}else{
				id++;
				b[id]=a[j];
			}
		}
		for(int j=1;j<id;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<m;i++){
		if(c[i]!=0){
			cout<<c[i]<<' ';
		}
	}
	return 0;
}
