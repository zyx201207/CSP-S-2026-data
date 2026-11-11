#include<bits/stdc++.h>
using namespace std;
long long mid,t,ans;
int n,c[210000],c1,c2,l,r,z;
char m[210000],a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>m[i];
		mid+=c[i];
	}
	mid=(mid+1)/2;
	for(int i=1;;i++){
		t=t+c[i];
		if(t>=mid){
			z=i;
			if(t-mid+1<=c[i]-(t-mid+1)){
				c[i]=c[i]-(t-mid)*2;
				z++;
			}
				else c[i]=c[i]-(c[i]-(t-mid));
			break;
		}
	}
	l=1,r=n,a=m[l],b=m[r],c1=c[l],c2=c[r];
	while(l<z){
		if(c1>=c2){
			if(a!=b) ans+=c2;
			c1=c1-c2;
			r--;
			c2=c[r];
			b=m[r];
		}
		else{
			if(a!=b) ans+=c1;
			c2=c2-c1;
			l++;
			c1=c[l];
			a=m[l];
		}
	}
	cout<<ans;
	return 0;
}
