#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],sum;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1;
	int r=n;
	while(l<r){
		long long mn=min(a[l],a[r]);
		a[l]-=mn;
		a[r]-=mn;
		if(c[l]!=c[r]){
			sum+=mn;
		}
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<sum;
}
