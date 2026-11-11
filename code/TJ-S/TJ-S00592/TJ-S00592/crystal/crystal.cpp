#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ma,mi;
bool check(int d){
	int h=m,o=0;
	for(int i=d-1;;i--){
		if(d-a[i]>=h){
			h-=d-a[i];
			o++;
		}
	}
	return o;
}
int main(){
	cin>>n>>m>>a[0];
	ma=a[0],mi=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	
	sort(a,a+n);
	bool f=1;
	for(int i=0;i<n-2;i++){
		if(a[i+1]-a[i]!=a[i+2]-a[i+1]){
			f=0;
			break;
		}
	}
	if(f){
		cout<<1;
		long long c=a[1]-a[0],l=a[0],g=0;
		for(int i=1;i<n;i++){
			l+=c*i;
			if(l<m) g++;
			else break;
		}
		printf("%.d",g);
		return 0;
	}
	int l=mi,r=ma;
	while(l<r){
		int mid=l+(r-l>>1);
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return 0;
}
