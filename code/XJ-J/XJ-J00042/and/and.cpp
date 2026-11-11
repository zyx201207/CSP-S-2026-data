#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m;
int a[maxn];
int ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(i==j || j==k || i==k){
					continue;
				}else{
					ans=max(ans,(a[i]&a[j]&a[k]));
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

