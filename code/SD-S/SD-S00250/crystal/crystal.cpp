#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500001],s[500001],l,r,mi,ma;
bool f(long long x,long long y){
	return a[x]*(x-y+1)-(s[x]-s[y-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		l=1;
		r=i;
		while(l<r){
			mi=(l+r)/2;
			if(f(i,mi)){
				r=mi;
			}else{
				l=mi+1;
			}
		}
		ma=max(ma,i-l+1);
	}
	cout<<ma;
	return 0;
} 
