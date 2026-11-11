#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n;
int a[N];
char c[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long cnt=0;
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			cnt+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}else if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}else{
			l++;
			r--;
		}
	}
	cout<<cnt;
	return 0;
}

