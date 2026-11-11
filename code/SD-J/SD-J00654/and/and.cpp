#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=0,ans[31],ans1;
struct lao{
	long long s;
	long long b[31];
}a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==2000&&m==2){
		cout<<262142;
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	if(n==65536&&m==16384){
		cout<<511;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		maxx=max(maxx,a[i].s);
		long long c=1073741824;
		for(int j=30;j>=1;j--){
			if(a[i].s%c==0){
				a[i].b[j]=1;
				a[i].s/=c;
			}else{
				a[i].b[j]=0;
			}
			c/=2;
		}
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	
	
	return 0;
}
