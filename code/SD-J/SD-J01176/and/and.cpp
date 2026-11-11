#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[i]){
				flag=1;
				swap(a[i],a[j]);
			}
		}
		if(flag==0){
			break;
		}
	}
	cout<<a[m];
	return 0;
} 
