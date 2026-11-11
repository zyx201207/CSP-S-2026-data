#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000],c[100000];
int main(){
//freopen("crystal1.in","r",stdin);
//freopen("crystal.out","w",stdout);
long long n,m;
cin>>n>>m;
int y=m;
for(int i=0;i<n;i++){
	cin>>a[i];
}
sort(a,a+n-1);
for(int i=0;i<n;i++){
	b[i]=a[i+1]-a[i]+b[i-1];
	c[i]=a[i+1]-a[i];
}
int ii=0,mmm=0;
for(int i=0;i<n;i++){
for(int j=1;j<n;){
	for(int k=1;k<n;){
		if(b[i+j]-b[i]>=b[i+k]-b[i]&&y-b[i+k]+b[i]>=0){
			y-=b[i+k]-b[i];
			ii++;
			k++;
		}else if(b[i+j]-b[i]<b[i+k]-b[i]&&y-b[i+j]+b[i]>=0){
			y-=b[i+j]-b[i];
			ii++;
			j++;
		}else{
			break;
		}
	}
}
mmm=max(ii,mmm);
ii=0;
y=m;
}
cout<<mmm<<0<<9;
}



