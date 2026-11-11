#include<bits/stdc++.h>
using namespace std;
int n,a[200001],esc=1048576,m,fl,b[200001][21],ans;
bool cnt(int x,int y){
	return x<y;
}
int dd(int x,int y){
	int dda[21]={0},ddb[21]={0},ddc[21]={0},z=0,dde=1048576;
	for(int j=20;j>=0;j--){
		if(x>=dde){
			dda[j]=1;
			x-=dde;
		}
		dde/=2;
    }
    dde=1048576;
    for(int j=20;j>=0;j--){
		if(y>=dde){
			ddb[j]=1;
			y-=dde;
		}
		dde/=2;
	}
	for(int j=0;j<=20;j++)
	    if(dda[j]==1&&ddb[j]==1)ddc[j]=1;
	    else ddc[j]=0;
	dde=1;
	for(int j=0;j<=20;j++){
	    z=z+ddc[j]*dde;
	    dde*=2;
	}
	return z; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)fl=1;
	}  
	sort(a+1,a+n+1,cnt);
	if(m==1)cout<<a[n];
	else{
		if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++)
			    ans=dd(ans,a[i]);
			cout<<ans;
		}
	}
	return 0;
}
