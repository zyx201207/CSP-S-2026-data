#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main(){

    //cout<<"freopen file name"<<endl;

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	
	int ans = 100000;
	
	for(int i=0;i<m;i++){
		ans = min(ans,a[n-i-1]);
		
		
	}
	
	cout<<ans;
	
    return 0;
}