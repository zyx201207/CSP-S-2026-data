#include<bits/stdc++.h>
using namespace std;

int n;
long long lst[500050],lmt;
long long maxz=0;
long long pnt;
long long cst;
bool check(long long x){
	for(long long i=x;i<=pnt;i++)cst+=lst[pnt]-lst[i];
	if(cst>lmt)return false;
	return true;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>lmt;
	bool xA=true,xB=true;
	for(long long i=1;i<=n;i++){
		cin>>lst[i];
	}sort(lst+1,lst+1+n);
	for(long long i=1;i<=n;i++){
		if(lst[i]!=i)xA=false;
		if(i>2)if(lst[i-1]-lst[i-2]!=lst[i]-lst[i-1])xB=false;
	}if(xA){
		long long ni=0;
		while(ni<n){
			ni++;
			if(lmt<ni){
				break;
			}lmt-=ni;
		}cout<<ni;
		return 0;
	}if(xB){
		long long ni=0;
		long long dc=lst[2]-lst[1];
		while(ni<n){
			ni++;
			if(lmt<ni*dc){
				break;
			}lmt-=ni*dc;
		}cout<<ni;
		return 0;
	}for(long long i=1;i<=n;i++){
		pnt=i;
		long long ans=0;
		long long l=1,r=pnt;
		long long mid;
		while(l<=r){
			cst=0;
			mid=(l+r)/2;
			if(check(mid)){
				ans=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
//		while(pnt>=1){
//			if(cst+lst[i]-lst[pnt]>lmt)break;
//			cst+=lst[i]-lst[pnt];
//			pnt--;
//		}
		maxz=max(maxz,i-ans+1);
	}cout<<maxz;
	return 0;
}
