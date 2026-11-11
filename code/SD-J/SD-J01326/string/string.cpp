#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<string>
#include<cstring>
using namespace std;
int n,l=1,r,a[200005];
char c[200005];
long long cnt=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<r){
		if(a[l]==0||a[r]==0) break;
		if(c[l]!=c[r]){
			cnt+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
		else if(a[l]<a[r]){
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
		else{
			r--;
			l++;
		}
	}
	cout<<cnt;
	return 0;
} 
