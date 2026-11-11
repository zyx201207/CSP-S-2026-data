#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(N+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(int i=n;i>=1;i--){
		int x=a[i];
		for(int j=i-1;j>j-m;j--){
			x=x&a[j];
		}
		if(x!=0){
			cout<<x;
			break;
		}
	}
	return 0;
}
