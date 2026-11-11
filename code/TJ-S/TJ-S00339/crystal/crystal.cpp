//Yibisa的解法，兄嘚的成绩
//谁给我报的这个smのcsp
//code by Yibisan no fiyingsis"aixi rks 16" 
#include<bits/stdc++.h>
using namespace std;
long long crs[500000];
long long to[201];
long long n,m,ans=1,bigans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){cin>>crs[i];}
	sort(crs,crs+n);
	long long dis[10000];
	for(int i=0;i<10000;i++){
		dis[i]=crs[i+1]-crs[i];
	}bool f=1;
	for(int i=0;i<9999;i++){
		if(dis[i+1]!=dis[i])f=0;
	}
	if(n<=5000){
		for(int i=1;i<n;i++){
			long long v=m,l=i-1;
			while(v>=crs[i]-crs[l]&&l>=0){
				v-=crs[i]-crs[l];
				ans+=1,l-=1;
			}
			bigans=max(ans,bigans);
			ans=1;
		}
		cout<<bigans;
	}else if(crs[0]>-101){
		for(int i=0;i<n;i++){to[crs[i]+100]+=1;}
		bigans=to[0];
		ans=to[1];
		for(int i=1;i<201;i++){
			long long v=m,l=i-1;
			if(to[l]==0){ans=to[i+1];continue;}
			while(v>=(i-l)*to[l]&&l>=0){
				v-=(i-l)*to[l];
				ans+=to[l],l-=1;
			}
			if(l>=0)(ans+=v/(i-l));
			bigans=max(ans,bigans);
			ans=to[i+1];
		}
		cout<<bigans;
	}else if(f){
		long long v=m;
		v/=dis[0];
		ans=1;
		for(int i=1;i<n;i++){
			if(2*v>=((long long)i*i+i))ans+=1;
			else break;
		}
		cout<<ans;
	}
	return 0;
}
