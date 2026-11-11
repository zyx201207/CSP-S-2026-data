#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a[100002],m,max_=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2){
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			int b=a[i]&a[k];
			 max_=max(max_,b);
		}
	}
	cout<<max_;
	}
	if(m==1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
	}
}
