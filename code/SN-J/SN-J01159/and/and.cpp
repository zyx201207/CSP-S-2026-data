#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(m==1){
		cout<<a[0];
		return 0;
	}
	long long maxn=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			long long b=a[i]&a[j];
			if(b>maxn){
				maxn=b;
			}
			if(maxn>=a[j+1]){
				cout<<maxn;
				return 0;
			}
		}
	}
	cout<<maxn;
	return 0;
}
