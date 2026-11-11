#include<bits/stdc++.h>

using namespace std;
int n;
long long m;
const int N=5e5+5;
long long a[N];
long long sum[N];
bool check(int ed,int x){
	if(a[ed]*(ed-x)-(sum[ed-1]-sum[x-1])<=m)return 1;
	return 0;
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
		sum[i]=a[i]+sum[i-1];
	}
	int mx=1;
    for(int i=n;i>=1;i--){
    	int l=1,r=i;
    	while(l<r){
    		int mid=l+r>>1;
    		if(check(i,mid)){
    			r=mid;
			}else{
				l=mid+1;
			}
		}
		mx=max(mx,i-l+1);
	}
	cout<<mx;
	return 0;
} 
