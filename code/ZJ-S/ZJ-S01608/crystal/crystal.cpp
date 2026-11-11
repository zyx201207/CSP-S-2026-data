#include<bits/stdc++.h>
using namespace std;
long long n , m , ii , jj , mm , dixian ,mmm;
long long an;
long long a[1000643];
bool haha(){
	if(a[2]-a[1]==a[3]-a[2]==a[4]-a[3]==a[5]-a[4]){
		return true;
	}
	return false;
}
bool laiba(long long x){
	an=0;
	for(long long i=dixian;i<x;i++){
		an+=a[x]-a[i];
	}
	if(an>m){
		return false;//能量不足 
	}
	else{
		return true;//能量足够实现 
	}
}

int main(){
	freopen("crystal0.in","r",stdin);
	freopen("crystal0.out","w",stdout);
	cin>>n;
	cin>>m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	while(dixian<n){
		jj=n;
		while (ii<=jj){
		mm=(ii+jj)/2;
		if(laiba(mm)){
			ii=mm+1;
			}
		else{
			jj=mm-1;
			}	
		}
	if (mmm<ii-dixian){
		mmm=ii-dixian;
	}
	if(haha()){
		break;
	}
	dixian++;
	}
	cout<<mmm;
	return 0;
} 
