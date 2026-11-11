#include<bits/stdc++.h>
using namespace std;
int a,b,c[1000005],d[1000005],e,f=0,zs=0,ss[1000005],n=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<b;i++){
		zs=0;
		d[1000005]={0};e=0;f=0;
		for(int j=i;j<a;j++){
			d[f]=c[j];
			f++;
			e=0;
			for(int o=0;o<e;o++){
				if(e==1){
					d[o]=0;
				}
				if(c[j]==d[o]){
					e=1;
					d[o]=c[j];
					f=o;
				}
			}
		}
		for(int j=0;j<f;j++){
			ss[n]=d[j];
			n++;
		}
	}
	for(int i=1;i<=a;i++){
		zs=0;
		for(int j=0;j<n;j++){
			if(ss[j]==i){
				zs++;
			}
		}
		if(zs!=0){
			cout<<zs<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
