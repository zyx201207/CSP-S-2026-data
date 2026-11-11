#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a[200005],n,m,maxn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=0;
			for(int k=1;k<=m;k++){
				cnt=a[k]&a[k+1];
			}
			if(cnt>maxn) maxn=cnt;
		} 
	}
	cout<<maxn;
	return 0;
}
