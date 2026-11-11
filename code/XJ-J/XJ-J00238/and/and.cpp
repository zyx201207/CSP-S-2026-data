#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N],ans[N],maxn,maxn1,temp[N];
void f(int k,int start){
	if(k==m+1){
		ans[1]=b[1];
		for(int j=2;j<=m;j++){
			ans[j]=ans[j-1]&b[j];
		}
		maxn=max(maxn,ans[m]);
		return;
	}
	for(int i=start;i<=n;i++){
		b[start]=a[i];
		f(k+1,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn1=max(a[i],maxn1);
	}
	if(m==1){
		cout<<maxn1;
		return 0;
	}
	if(m==n){
		temp[1]=a[1];
		for(int i=2;i<=n;i++){
			temp[i]=temp[i-1]&a[i];
		}
		cout<<temp[n];
		return 0;
	}
	f(1,1);
	cout<<maxn;
	return 0;
}
