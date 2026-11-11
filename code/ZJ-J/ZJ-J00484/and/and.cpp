#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m,res=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]&(1<<i)){
				cnt++;
			}
		}
		if(cnt>=m){
			res+=1<<i;
			for(int j=1;j<=n;j++){
				if(!(a[j]&(1<<i))){
					a[j] = 0;
				}
			}
		}
	}
	cout<<res;
	return 0;
}
