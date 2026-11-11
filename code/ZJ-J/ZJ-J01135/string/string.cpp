#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,mid,s,o,p,j,w,t,f,i,gs,a[200010],z,zg[200010],yg[200010];
char yz[200010],zz[200010],b[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i]>>b[i],z+=a[i];
    mid=z/2;
    for(i=1;i<=n;i++){
    	if(gs+a[i]>mid){
    		f=1;zg[++t]=mid-gs;zz[t]=b[i];break;
		}
    	gs+=a[i];
    	zz[++t]=b[i];zg[t]=a[i];
    	if(gs==mid) break;
	}
	if(f==1) yz[++w]=b[i],yg[w]=a[i]-zg[t];
	if(f==0&&z%2==1) yz[++w]=b[i+1],yg[w]=a[i+1]-1,i++;
    for(j=i+1;j<=n;j++) yz[++w]=b[j],yg[w]=a[j];
	o=1;p=w;
	while(o<=t&&p>=1){
		if(zz[o]!=yz[p]){
			if(zg[o]==yg[p]) s=s+zg[o],o++,p--;
			else if(zg[o]<yg[p]) s=s+zg[o],yg[p]-=zg[o],o++;
			else if(zg[o]>yg[p]) s=s+yg[p],zg[o]-=yg[p],p--;
		}
		if(zz[o]==yz[p]){
			if(zg[o]==yg[p]) o++,p--;
			else if(zg[o]<yg[p]) yg[p]-=zg[o],o++;
			else if(zg[o]>yg[p]) zg[o]-=yg[p],p--;
		}
	}
	cout<<s;
}
