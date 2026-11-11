#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005];
int MX=0,ALLAND=0;
int Dp_pre[60008];
int Dp_now[60008];
bool popcheck(int mam){
	int num=0;
	while(mam){
	    num++;
		mam-=(mam&(-mam));
		if(num>m)return 0;
	}
	return num==m;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		MX=max(MX,arr[i]);
		if(i==1)ALLAND=arr[i];
		else ALLAND&=arr[i];
	}
	if(n==m){
		cout<<ALLAND;
		return 0;
	}
	else if(m==1){
		cout<<MX;
		return 0;
	}
	int ans=0;
	for(int mask=0;mask<(1<<n);mask++){
		if(!popcheck(mask))continue;
		int tmp=-100;
		for(int i=0;i<n;i++){
			if(mask&(1<<i)){
				if(tmp==-100)tmp=arr[i+1];
				else tmp&=arr[i+1];
			}
		}
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
} 
