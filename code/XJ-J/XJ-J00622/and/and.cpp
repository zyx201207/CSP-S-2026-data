#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100100],bj[10010][10010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
	}
	long long mx=-1e9;
	
	for(int l=1;l<=k;l++){
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i||bj[i][j]==1){
				continue;
			}
			b[i]=max(b[i],a[i]&a[j]);
			bj[i][j]=1;
		}
		a[i]=b[i];
	}
}
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
	}
	cout<<mx;
	return 0;
} 
