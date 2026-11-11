#include<bits/stdc++.h>
using namespace std;
int c[500001],d[500001],e[500001],p[500001],sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}sort(c+1,c+a+1);
	for(int i=1;i<=a-1;i++){
	d[i]=c[i+1]-c[i];
	}for(int i=1;i<=a-1;i++){
		e[i]=e[i-1]+d[i]*i;
	}for(int i=1;i<=a-1;i++){
	
	if(e[i]==b){
	p[i]=i+1;
	sum++;
	}
	}sort(p+1,p+sum+1);
	cout<<p[sum+1]; 
	return 0;
}

