#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,mx=-1;
long long m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int j=i-1,ans=1;
		long long mm=m;
		while(mm>=0&&j>0){
			mm-=a[i]-a[j];
			j--;
			if(mm>=0) ans++;
		}
		mx=max(ans,mx);
	}
	cout<<mx;
	return 0;
}