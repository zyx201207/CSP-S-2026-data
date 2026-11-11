#include<bits/stdc++.h>
using namespace std;
int a[200005],sum[200005];
bool b[200005];
int two(int z){
	int c=1,num=0;
	while(z!=0){
		num+=z%2*c;
		c*=10;
		z/=2;
	}
	return num;
}
int awy(int y,int z){
	int c=0,num=0;
	while(y!=0||z!=0){
		if(y%10==z%10==1){
			num+=pow(2,c);
		}
		c++;
		y/=10;
		z/=10;
	}
	return num; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int maxn=0,maxi;
		for(int j=1;j<=n;j++){
			if(a[j]>maxn&&b[j]==0){
				maxn=a[j];
				maxi=j;
			}
		}
		sum[i]=maxn;
		b[maxi]=1;
	}
	for(int i=1;i<m;i++){
		sum[i+1]=awy(two(sum[i]),two(sum[i+1]));
		x+=sum[i+1];
	}
	cout<<x;
	return 0;
}
