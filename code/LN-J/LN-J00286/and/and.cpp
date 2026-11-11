#include<bits/stdc++.h>
using namespace std;
int a[100005],l[10005];
int x[100005][100005],y[100005][100005]，h[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		x[i][j]=a[i]%2;
		a[i]=a[i]/2;
		h[i]=h[i]+1；
	}
}
for(int k=h[i];k>=1,k--){
	y[i][j]=x[i][k];
}
	

}
