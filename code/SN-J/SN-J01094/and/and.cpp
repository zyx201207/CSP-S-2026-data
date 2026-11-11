#include<bits/stdc++.h>
#include<math.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==n){
		cin>>a[1];
		int jdj=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			jdj=(jdj&a[i]);
		}
		cout<<jdj;
		return 0; 
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	} 
	if(m==1) {
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==2){
		int s1=a[n],s2=a[n-1];
		cout<<(s1&s2);
		return 0;
	}
	//A
	int jjj=a[1];
	for(int i=n;i>=n-m+1;i--){
		jjj=(jjj&a[i]);
	}
	cout<<jjj;
	return 0;
}
