#include<bits/stdc++.h>
using namespace std;
int a[2000005];
bool cmp(int x,int y){
	return x>y;
}
int maxn=0;
int b[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int sum=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			sum=sum&a[j];
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	return 0;
} 
