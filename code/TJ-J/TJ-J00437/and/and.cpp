#include<bits/stdc++.h>
using namespace std;
long long a[10005][10005],b[10005];
int n,m;
bool s(long long a,long long b){
	return a<b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1,s);
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			a[i][j]=a[i-1][j];
			if(j+1<=m&&a[i-1][j+1]){
				a[i][j]=max(a[i][j],(a[i-1][j+1]&b[i]));
			}else if(j+1<=m){
				a[i][j]=max(a[i][j],b[i]);
			}
		}
	}
	cout<<a[n][0];
	return 0;
}
