#include<bits/stdc++.h>
using namespace std;
long long n;
long long aa[200005],aa1[200005],zxb,yxb,mid,zsy,ysy,zcd,zs,kc,key,ans;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char bb;
		cin>>aa[i];
		cin>>bb;
		aa1[i]=bb-'a'+1;
		zcd=zcd+aa[i];
	}
	mid=zcd/2;
	zxb=1;
	yxb=n;
	zsy=aa[1];
	ysy=aa[n];
	while(1){
		kc=min(zsy,ysy);
		if((zs+kc)>mid){
			kc=mid-zs;
			key=1;
		}
		if(aa1[zxb]!=aa1[yxb]){
			ans=kc+ans;
		}
		if(key){
			break;
		}
		zsy=zsy-kc;
		ysy=ysy-kc;
		zs=zs+kc;
		if(zsy==0){
			zxb++;
			zsy=aa[zxb];
		}
		if(ysy==0){
			yxb--;
			ysy=aa[yxb];
		}
	}
	cout<<ans;
	return 0;
}
