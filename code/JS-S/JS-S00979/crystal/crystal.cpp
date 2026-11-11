#include<bits/stdc++.h>
using namespace std;
int n,m,ans,sum=0;
int a[100005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
		sum=a[i]+1;
		
		if(sum==a[i+1]){
			ans++;
		}
	}
	cout<<ans;
}

