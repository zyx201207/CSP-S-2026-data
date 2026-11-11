#include<bits/stdc++.h>
using namespace std;
int N[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int m,n,ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>N[i];
	}
	sort(N+1,N+n+1);
	for(int i=n-m+1;i<=n;i++){
		if(i==n-m+1){
			ans=N[n-m+1];
		}else{
			ans=ans&N[i];
		}
	}
	cout<<ans;
    return 0;
}
