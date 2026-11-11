#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+m+1,greater<long long>());
	int k=a[1],maxn=0;
	if(n==2){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				int k=a[i];
				k&=a[j];
				maxn=max(k,maxn);
			}
		}
	}
	else{
		for(int i=2;i<=n;i++){
			k&=a[i];
			maxn=k;
		}
	}
	cout<<maxn;
	return 0;
}                                    