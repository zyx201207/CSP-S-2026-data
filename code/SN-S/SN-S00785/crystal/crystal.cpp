//SN-S00785
#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],maxn=-1e9;
unsigned long long m;
bool checka(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			return false;
		}
	}
	return true;
}
bool checkb(){
	int c=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if((a[i]-a[i-1])!=c){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(checka()){
		int l=1,r=n;
		while(l<r){
			long long mid=(l+r+1)/2;
			unsigned long long wei=(mid-1)*mid/2;
			if(wei>m){
				r=mid-1;
			}else{
				l=mid;
			}
		}
		cout<<l;
	}else if(checkb()){
		int l=1,r=n,c=a[2]-a[1];
		while(l<r){
			long long mid=(l+r+1)/2;
			unsigned long long wei=((mid-1)*mid*c)/2;
			if(wei>m){
				r=mid-1;
			}else{
				l=mid;
			}
		}
		cout<<l;
	}else{
		for(int i=1;i<=n;i++){
			long long f=0;
			unsigned long long ans=0;
			for(int j=i-1;j>0;j--){
				ans+=a[i]-a[j];
				if(ans>m){
					f=1;
					maxn=max(maxn,(long long)i-j);
					break;
				}
			}
			if(!f){
				maxn=max((long long)i,maxn);
			}
		}
		cout<<maxn;
	}
	return 0;
} 
