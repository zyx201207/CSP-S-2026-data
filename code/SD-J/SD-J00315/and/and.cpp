#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long n,m;
long long minn=1e9,maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;j++){
			minn=a[i]&&a[j];
			if(a[i]&&a[j+1]<minn){
				minn=a[i]&&a[j+1];
			}else{
				maxn=a[i]&&a[j+1]; 
			}
		}
	}
	cout << maxn;
	
	return 0;
} 
