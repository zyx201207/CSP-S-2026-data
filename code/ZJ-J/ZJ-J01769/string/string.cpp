#include<bits/stdc++.h>
using namespace std;
#define lll long long
char c[200005],dc,dz,dy;
bool hg[100000000];string s="";
lll n,a[200005],l,d,z,y,mid,kj;
void ru(lll &a){
	a=0;char in=getchar();bool zf=0;
	while(in<'0'||in>'9'){if(in=='-')zf=1;in=getchar();}
	while(in>='0'&&in<='9'){a=(a<<1)+(a<<3)+(in^48);in=getchar();}
	if(zf)a=-a;
}
bool hw(){
	for(int i=0,j=n-1;i<j;i++,j--){
		if(s[i]!=s[j])return 0;
	}
	return 1;
}
void S(lll cs,lll I){
	if(hw()){d=min(d,cs);return;}
	if(cs>d)return;
	for(int i=I+1;i<n;i++){
		if(hg[i])continue;
		for(int j=i+1;j<n;j++){
			if(!hg[j]){
				hg[i]=hg[j]=1;
				swap(s[i],s[j]);
				S(cs+1,i);
				swap(s[i],s[j]);
				hg[i]=hg[j]=0;
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ru(n);
	if(n<=10){
		d=1e18;lll x;
		for(int i=1;i<=n;i++){
			ru(x);dc=getchar();
			while(dc<'a'||dc>'z')dc=getchar();
			while(x--)s+=dc;
		}
		n=s.size();
		S(0,-1);cout<<d;
	}
	else{
		for(int i=1;i<=n;i++){
			ru(a[i]);
			l+=a[i];
			dc=getchar();
			while(dc<'a'||dc>'z')dc=getchar();
			c[i]=dc;
			if(c[i]==c[i-1]){
				a[i-1]+=a[i];i--;n--;
			}
		}
		dz=c[1];dy=c[n];
		if(dz!=dy)d+=min(a[1],a[n]);
		if(a[1]>a[n])z=a[1]-a[n];
		else y=a[n]-a[1];
		for(lll i=2,j=n-1;i<=j;){
			if(z<y){
				z+=a[i];dz=c[i];i++;
				if(dz!=dy){
					if(z>y){d+=y;z-=y;y=0;}
					else {d+=z;y-=z;z=0;}
				}
				else{
					if(z>y){z-=y;y=0;}
					else {y-=z;z=0;}
				}
			}
			else if(z>y){
				y+=a[j];dy=c[j];j--;
				if(dz!=dy){
					if(z>y){d+=y;z-=y;y=0;}
					else {d+=z;y-=z;z=0;}
				}
				else{
					if(z>y){z-=y;y=0;}
					else {y-=z;z=0;}
				}
			}
			else{
				z+=a[i];dz=c[i];i++;
				y+=a[j];dy=c[j];j--;
				if(dz!=dy)d+=min(a[1],a[n]);
				if(a[1]>a[n])z=a[1]-a[n];
				else y=a[n]-a[1];
			}
			if(i==j)mid=i;
		}
		cout<<d;
	}
}