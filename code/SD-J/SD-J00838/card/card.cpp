#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
int a=1,b=1,c,d,e[10000],f[20000],g,h[10000];
cin>>c>>d;
for(int i=1;i<=c;i++){
	cin>>f[i];
	e[i]=f[i];
}
for(int p=0;p<c;p++){

for(int i=1+p;i<=c;i++){
	for(int j=i+1;j<=c;j++){
	if(f[i]==f[j]){
		for(int o=i;o<j;o++){
			f[o]=0;
		}
	}
}

	
}
for(int o=1;o<=d;o++){
			for(int j=p+1;j<=c;j++){
			if(f[j]==o){
				h[o]++;
			}
			}
		}
for(int l=1;l<=c;l++){
	f[l]=e[l];
}}
for(int o=1;o<=d;o++){
	cout<<h[o]<<" ";
}
	return 0;
} 

