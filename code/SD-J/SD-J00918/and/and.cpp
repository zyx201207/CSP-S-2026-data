#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],b[200005],b1[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i<=m){
			b[i]=a[i];
			if(i==1){
				b1[i]=a[i];
			}else{
				b1[i]=b1[i-1]&b[i];
			}
			
		}
	}
	for(int i=m+1;i<=n;i++){
		int t=m;
		for(int j=m;j>=1;j--){
			int z=b1[j-1]&a[i];
			int z1=b[2]&a[i];
			if(j==1){
				if(z1>b1[j+1]){
					b[j]=a[i];
					t=j;
					break;
				}
			}else if(z>b1[j]){
				b[j]=a[i];
				t=j;
				break;
			}
		}
		for(int j=t;j<=m;j++){
			b1[j]=b1[j-1]&b[j];
		}
	}
	num=b[1];
	for(int i=1;i<=m;i++){
		num=num&b[i];
	}
	cout<<num;
	return 0;
}
