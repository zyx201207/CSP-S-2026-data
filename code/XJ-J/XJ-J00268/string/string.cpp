#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cin>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>=a[r]){
				a[l]-=a[r];
				a[r]=0;
				--r;
				if(a[l]==0)++l;
			}else{
				a[r]-=a[l];
				a[l]=0;
				++l;
				if(a[r]==0)--r;
			}
		}else{
			if(a[l]>=a[r]){
				a[l]-=a[r];
				cnt+=a[r];
				a[r]=0;
				--r;
				if(a[l]==0)++l;
			}else{
				a[r]-=a[l];
				cnt+=a[l];
				a[l]=0;
				++l;
				if(a[r]==0)--r;
			}
		}
	}
	cout<<cnt;
	return 0;
}
