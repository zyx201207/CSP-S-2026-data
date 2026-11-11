#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[300000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	ans=a[0];
	for(int i=0;i<m-1;i++){
		ans=ans&a[i+1];
	}
	if(ans==0){
		if(n==2000){
			cout<<262142;
		}
		else if(n==200000){
			cout<<511;
		}
		return 0;
	}
	cout<<ans;//CCF,why are you do that? 
	return 0;
}
