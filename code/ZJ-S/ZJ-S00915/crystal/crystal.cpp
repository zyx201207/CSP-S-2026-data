#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005;
int n,anf,ang,ank,anl,m,ans,a[maxn],b[maxn],len,flag,p,gc,flag2,flag3;
int minn(int l1,int l2){
	if(l1<=l2){return l1;}
	else{return l2;}
}
int maxx(int l1,int l2){
	if(l1>=l2){return l1;}
	else{return l2;}
}
bool check(int k){
//	int anf=0,ang=0;
//	for(int i=1;i<=n;i++){
//		if(anf>m){ans=maxx(ans,ang);return 0;}
//		if(a[i]>a[k]){
//			if(anf<=m){ans=maxx(ans,ang);return 1;}
//			else{ans=maxx(ans,ang);return 0;}
//		}else{anf=anf+(a[k]-a[i]);ang++;}
//	}
//	if(anf>m){ans=maxx(ans,ang);return 0;}
//	else{ans=maxx(ans,ang);return 1;}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		//mina=minn(mina,a[i]);
	}sort(a+1,a+n+1);
//	l=1;r=n;
//	cerr<<l<<" "<<r<<"\n";
//	while(l<=r){
//		mid=(l+r)/2;
//		cerr<<mid<<":mid\n";
//		if(check(mid)){l=mid+1;}
//		else{r=mid-1;}
//	}cerr<<ans;
	flag=1;
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])!=(a[2]-a[1])){flag=0;break;}
	}if(flag==1){
		gc=a[2]-a[1];
		for(int i=1;i<=n-1;i++){
			p=((1+i)*i/2*gc);
			if(p>m){cout<<i;return 0;}
		}cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){if(a[i]!=b[len]){b[++len]=a[i];}}
	for(int i2=1;i2<=len;i2++){
		ang=m;anl=0;flag2=1;flag3=1;
		for(int j=1;j<=n;j++){
			if(a[j]>b[i2]){anf=j-1;flag3=0;break;}
		}if(flag3==1){anf=n;}
		for(int j=anf;j>=1;j--){
			if(ang-(b[i2]-a[j])<0){ans=maxx(ans,anl);flag2=0;break;}
			ang=ang-(b[i2]-a[j]);anl++;
		}if(flag2==1){ans=maxx(ans,anf);}
	}cout<<ans;
	return 0;
}