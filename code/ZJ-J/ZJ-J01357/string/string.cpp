#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;
char nx[200005];
int nv[200005];
int n,px1,px2,p1,p2;
ll sl,p,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	sl=0;p=0;ans=0;p1=0;p2=0;px1=0;px2=n-1;
	for(int i=0;i<n;i++){
		cin>>nv[i]>>nx[i];
		sl+=nv[i];
	}
	ll sl5=sl/2;
	while(px1<px2){
		int vx=min(nv[px1]-p1,nv[px2]-p2);
		if(nx[px1]!=nx[px2]){
			ans+=vx;
		}
		p1+=vx;p2+=vx;
		if(p1==nv[px1]){
			px1++;p1=0;
		}
		if(p2==nv[px2]){
			px2--;p2=0;
		}
	}
	cout<<ans;
	return 0;
}