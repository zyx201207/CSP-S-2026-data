#include <bits/stdc++.h>
using namespace std;

struct zu{
	int shl;
	char zm;
};
zu zl[200005];
zu zr[200005];
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	int sl;
	char c;
	int z=0;
	for(int i=0; i<n; i++){
		cin>>sl>>c;
		zl[i].shl=sl;
		zl[i].zm=c;
		zr[n-i-1].shl=sl;
		zr[n-i-1].zm=c;
		z+=sl;
	}
	int cks=0;
	int dqz=0;
	int dqy=0;
	while(1){
		if(zl[dqz].shl>zr[dqy].shl){
			if(zl[dqz].zm != zr[dqy].zm){
				ans+=zr[dqy].shl;
			}
			zl[dqz].shl-=zr[dqy].shl;
			cks+=zr[dqy].shl;
			dqy++;
		}else{
			if(zl[dqz].zm != zr[dqy].zm){
				ans+=zl[dqz].shl;		
			}
			zr[dqy].shl-=zl[dqz].shl;
			if(zr[dqy].shl==0){
				dqy++;
			}
			cks+=zl[dqz].shl;
			dqz++;
		}
		if(cks>=z/2){
			break;
		}
	}
	cout<<ans;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////h
	return 0;
} 
