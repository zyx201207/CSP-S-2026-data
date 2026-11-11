#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool f[200005];
int maxn=0;
int and1(int x,int y){
	int a[45]={0},b[45]={0};
	int k=0,k1=0,k2=0;
	while(x!=0){
		k1++;
		a[k1]=x%2;
		x=x/2; 
	}
	while(y!=0){
		k2++;
		b[k2]=y%2;
		y=y/2;	
	}
	k=min(k1,k2);
	int c=0;
	for(int i=k;i>=1;i--){
		if(a[i]=b[i]){
			c=c*10+1;
		}else{
			c=c*10;
		}
	}
	int c1=0;
	int h=1;
	while(c!=0){
		c1+=c%10*h;
		h=h*2;
		c=c/10;
	}
	return c1;
}
void dg(int num,int sum,int step){
	if(num==m){
		maxn=max(maxn,sum);
		return;
	}
	for(int i=step;i<=n;i++){
		f[i]=1;
		if(num==0)dg(num+1,a[i],i+1);
		else dg(num+1,and1(sum,a[i]),i+1);
		f[i]=0;
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dg(0,0,1);
	cout<<maxn;
    fclose(stdin);
	fclose(stdout);
	return 0;
}
