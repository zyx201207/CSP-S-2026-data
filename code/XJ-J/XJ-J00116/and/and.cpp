#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,maxx=-1;
int a[N];
bool mark[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]&a[j]>maxx){
				maxx=a[i]&a[j];
				mark[i]=1;
				mark[j]=1;
			}
		}
	}
//	k--;
//	while(k--){
//		for(int i=4;i<=n;i++){
//			if(maxx&a[i]>maxx&a[i-1]&&!mark[i]){
//				maxx=a[i]&maxx;
//				mark[i]=1;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		cout<<mark[i]<<" ";
//	}
//	cout<<maxx;
	return 0;
}
