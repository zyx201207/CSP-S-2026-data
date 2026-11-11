#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[n];
	}
	if(m==1){
		sort(a,a+n,greater<int>{});
		cout<<a[0];
		return 0;
	}
	if(m==n){
		int t;
		t=a[0]&a[1];
		for(int i=1;i<n-1;i++){
			t=t&a[i+1];
		}
		cout<<t;
	}
	return 0;
}
