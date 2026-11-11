#include<bits/stdc++.h>
using namespace std;
bool my(int a,int b){
	return a>b;
}
int n,m,a[200005],maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,my);
	for(int i=1;i<=n-m+1;i++){
		int x=pow(2,30)-1;
		for(int j=i;j<=i+m-1;j++){
			x&=a[j];
		}
		maxx=max(x,maxx);
	}
	cout<<maxx;
	return 0;
} 
