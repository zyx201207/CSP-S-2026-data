#include<bits/stdc++.h>
using namespace std;
int a[2000000];
int c,t;
int n,d,sum=0;
int xyb(int i){
	int s=1;
	while(a[i+s]-a[i]<=d){
		s++;
	}
	return i+s-1;
}
int zdbs(int i,int j){
	if(a[j]-a[i]<=d){
		return 1;
	}else{
		i=xyb(i);
		return 1+zdbs(i,j);
	}
}
int bs(int i,int j){
	if(a[i]>=a[j]) return 0;
	for(int x=1;x<=d;x++){
		return 1+bs(i+x,j);
	}
}
int zd(int i,int j){
	int bs1=zdbs(i,j);
	return 2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int x=0;x<t;x++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n-2;i++){
			for(int j=2;j+i<n;j++)
			if(zd(i,i+j)==2) sum++;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
