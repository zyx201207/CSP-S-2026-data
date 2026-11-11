#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],zs[200005],ys[200005],ans,sum,cnt1,cnt2;
char c[200005],zz[200005],yz[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}ll now=0,t=1;
	while(1){
		if(now+a[t]<=sum/2){
			now+=a[t];
			zs[++cnt1]=a[t];
			zz[cnt1]=c[t];
			t++;
		}else{
			if(now!=sum/2){
				zs[++cnt1]=sum/2-now;
				zz[cnt1]=c[t];
				a[t]-=(sum/2-now);
			}if(sum%2==1){
				a[t]--;
				if(a[t]==0)t++;
			}break;
		}
	}for(int i=t; i<=n; i++){
		ys[++cnt2]=a[i];
		yz[cnt2]=c[i];
	}ll z=0,y=0,l=1,r=cnt2;
	char zb,yb;
	while(l<=cnt1||r>=1){
		if(z==0&&y==0){
			z+=zs[l];
			zb=zz[l];
			y+=ys[r];
			yb=yz[r];
			l++;
			r--;
		}else if(z==0){
			z+=zs[l];
			zb=zz[l];
			l++;
		}else if(y==0){
			y+=ys[r];
			yb=yz[r];
			r--;
		}ll t=min(z,y);
		if(zb!=yb)ans+=t;
		z-=t;
		y-=t;
	}cout<<ans;
	return 0;
}