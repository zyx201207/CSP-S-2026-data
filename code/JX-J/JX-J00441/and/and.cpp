#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans,a1[1000001],a2[1000001],a3[1000001],p=1,q=1;
int cmp(int x,int y){
	return x>y;
}int hyz(int x,int y){
	while(x!=0){a1[p++]=x%2;x/=2;}
	while(y!=0){a2[q++]=y%2;y/=2;}
	for(int i=max(p,q)-1;i>=1;i--){
		if(a1[i]==1&&a2[i]==1) a3[i]=1;
		else a3[i]=0;
	}int h=max(p,q);
	while(a3[h]==0) h--;
	int num=0,k=0;
	for(int i=1;i<h;i++){
		num+=a[i]*pow(2,k);
		k++;
	}memset(a1,0,sizeof(a1));memset(a2,0,sizeof(a2));memset(a3,0,sizeof(a3));
	p=1;q=1;
	return num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m==1){cout<<hyz(a[1],a[1]);return 0;}
	if(m==2){cout<<hyz(a[1],a[2]);return 0;}
	int next=hyz(a[1],a[2]);
	for(int i=3;i<=m;i++){
		ans=hyz(next,a[i]);
		next=ans;
	}cout<<ans;
	return 0;
}
