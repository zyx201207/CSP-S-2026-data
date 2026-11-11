#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,p,q=0;
	cin>>n>>m;
	int a[500001]={};
	long long b[500001],c[500001],d[500001]={};	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int y=n;y>0;y--){
	

	for(int i=0;i<y;i++){
		if(a[i]<a[i+1]){
			q=1;
		}
	}
	for(int i=0;i<y;i++){
		if(c[a[p]]==1){
			p=i;
			b[p]=a[i];
			
		}
		c[b[p]]=1;
		
	}
	for(int i=p;i<y;i++){
		if(c[i]!=0){
			d[b[p]]++;
		}
	}
	for(int i=0;i<500001;i++){
		a[i]=0;
		b[i]=0;
		c[i]=0;
		d[i]=0;
	}
	}
	if(q=1){
		for(int i=0;i<m;i++){
		cout<<i+1<<" ";
	}
	}else{

	for(int i=0;i<m;i++){
		cout<<d[i]<<" ";
	}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}