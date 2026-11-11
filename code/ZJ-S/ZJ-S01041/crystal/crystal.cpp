#include<bits/stdc++.h>
using namespace std;
unsigned long long readu(){
	unsigned long long ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)){ret=ret*10+(ch-'0');ch=getchar();}
	return ret;
}
long long readl(){
	long long ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch='-') f=-1;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+(ch-'0');ch=getchar();}
	return ret*f;
}
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch='-') f=-1;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+(ch-'0');ch=getchar();}
	return ret*f;
}
int n,ans;
long long a[500005];
unsigned long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=readu();
	for(int i=1;i<=n;i++) a[i]=readl();
	sort(a+1,a+1+n);
	if(n<=5000){
	for(int i=1;i<=n;i++){
		int l=i-1,r=i+1,xans=1;
		unsigned long long xm=m;
		while(xm>=0){
			long long dl=abs(a[i]-a[l]),dr=abs(a[r]-a[i]);
			if(l>=1&&r<=n&&xm>=min(dl,dr)){
				if(dl<dr) xm-=dl,l--,xans++;
				else xm-=dr,r++,xans++;
			}else if(l>=1&&xm>=dl){
				xm-=dl,l--,xans++;
			}else if(r<=n&&xm>=dr){
				xm-=dr,r++,xans++;
			}else break;
		}
		ans=max(ans,xans);
		
		
	}
	}else{
		int i=(n+1)/2;
		int l=i-1,r=i+1,xans=1;
		unsigned long long xm=m;
		while(xm>=0){
			long long dl=abs(a[i]-a[l]),dr=abs(a[r]-a[i]);
			if(l>=1&&r<=n&&xm>=min(dl,dr)){
				if(dl<dr) xm-=dl,l--,xans++;
				else xm-=dr,r++,xans++;
			}else if(l>=1&&r>n&&xm>=dl){
				xm-=dl,l--,xans++;
			}else if(r<=n&&l<1&&xm>=dr){
				xm-=dr,r++,xans++;
			}else break;
		}
		
		ans=max(ans,xans);
		
	}
	printf("%d\n",ans);
	return 0;
}
