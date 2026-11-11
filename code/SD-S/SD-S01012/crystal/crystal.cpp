#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int M=1e12;
int n,m,a[N],b[N],c[N],T[300],y[N],nex;
int check(int r){
	/*
	int cnt=0,t=m,r=l;
	while(t>=0&&r<=n){
		int y=a[r]-a[l];
		if(y<=t){
			t-=y;
			cnt++;
			r++;
		}
		else{
			break;
		}
	}
	cout<<cnt<<'\n';
	return cnt;
	*/
	//cout<<r<<":\n";
	int rr=r,l=1;
	while(1){
		if(l>=rr) break;
		int mid=(rr-1+l)/2;
		if(a[r]*(r-mid)-b[r]+b[mid]<=m) rr=mid;
		else l=mid+1;
		//cout<<l<<" "<<ll<<'\n';
	}
	cout<<l<<" "<<r<<" "<<r-l+1<<'\n';
	return r-l+1;
	
}
signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int minn=M;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
	}
	if(minn>0) minn=0;
	else minn=-minn;
	for(int i=1;i<=n;i++){
		a[i]+=minn;
		b[i]=b[i-1]+a[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++) ans=max(ans,check(i));
	cout<<ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
//我他妈真牛逼 想出正解不会做的来了 
