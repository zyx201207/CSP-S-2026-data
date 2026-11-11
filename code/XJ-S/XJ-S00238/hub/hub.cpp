#include<bits/stdc++.h>
using namespace std;

int n;
long long lst[500050],lmt;
long long maxz=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>lmt;
	bool xA=true,xB=true;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}sort(lst+1,lst+1+n);
	for(int i=1;i<=n;i++){
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
	}for(int i=1;i<=n;i++){
		long long pnt=i;
		long long cst=0;
		while(pnt>=1){
			if(cst+lst[i]-lst[pnt]>lmt)break;
			cst+=lst[i]-lst[pnt];
			pnt--;
		}maxz=max(maxz,i-pnt);
	}cout<<maxz;
	return 0;
}
