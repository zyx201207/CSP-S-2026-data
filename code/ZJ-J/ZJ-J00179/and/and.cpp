#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==2){
		int maxn=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int aa=a[i]&a[j];
				maxn=max(aa,maxn);
			}
		}
		cout<<maxn;
		return 0;
	}
	long long ans=a[1];
	for(int i=2;i<=m;i++) ans=ans&a[i];
	cout<<ans;
	return 0;
}