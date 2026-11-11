#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,zhong,n,k,t,w,tt,ww,t2,j,w2,ans,c[300010];
string s;
struct no{
	int x;char y;
}a[300010],d[300010],e[300010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y,c[i]=c[i-1]+a[i].x;
//	zhong=c[n]/2;
//	for(i=1;i<=n;i++)
//		if(c[i-1]<zhong&&zhong<=c[i])
//			break;
//	k=i; 
//	if(c[n]%2==0){
//		if(zhong==c[k]){
//			for(i=1;i<=k;i++)d[++t]=a[i];
//			for(i=k+1;i<=n;i++)e[++w]=a[i];
//		}
//		else{
//			for(i=1;i<k;i++)d[++t]=a[i];
//			d[++t].x=zhong-c[k-1];d[t].y=a[k].y;
//			e[++w].x=c[k]-zhong;e[w].y=a[k].y;
//			for(i=k+1;i<=n;i++)e[++w]=a[i];
//		}
//	}
//	else{
//		if(zhong==c[k]){
//			for(i=1;i<=k;i++)d[++t]=a[i];
//			e[++w].x=a[k+1].x-1;e[w].y=a[k+1].y;
//			for(i=k+2;i<=n;i++)e[++w]=a[i];
//		}
//		else{
//			for(i=1;i<k;i++)d[++t]=a[i];
//			d[++t].x=zhong-c[k-1];d[t].y=a[k].y;
//			e[++w].x=a[k].x-(zhong-c[k-1])-1;e[w].y=a[k].y;
//			for(i=k+1;i<=n;i++)e[++w]=a[i];
//		}
//	}
//	tt=0;ww=0;
//	t2=t;w2=1;
//	while(t2>0&&w2<=w){
//		if(d[t2].y==e[w2].y){
//			if(d[t2].x-tt==e[w2].x-ww)t2--,w2++,tt=0,ww=0;
//			else if(d[t2].x-tt<e[w2].x-ww)ww+=d[t2].x-tt,t2--,tt=0;
//			else tt+=e[w2].x-ww,w2++,ww=0;
//		}
//		else{
//			if(d[t2].x-tt==e[w2].x-ww)ans+=d[t2].x-tt,t2--,w2++,tt=0,ww=0;
//			else if(d[t2].x-tt<e[w2].x-ww)ans+=d[t2].x-tt,ww+=d[t2].x-tt,t2--,tt=0;
//			else ans+=e[w2].x-ww,tt+=e[w2].x-w2,w2++,ww=0;
//		}
//	}
//	cout<<ans;
s=" ";
	for(i=1;i<=n;i++){
		for(j=1;j<=a[i].x;j++)s=s+a[i].y;
	}
	t=1;w=s.size();w--;
	while(t<=w){
		if(s[t]!=s[w])ans++;
		t++;w--;
	}
	cout<<ans;
	return 0;
}
