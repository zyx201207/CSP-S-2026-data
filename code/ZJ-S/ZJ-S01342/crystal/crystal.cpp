#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001],ans=0,x=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	x=a[i]-a[i-1];
	}
	//cout<<m;
	for(int j=x,i=1;i<=n;j+=x,i++){		
		m-=j;
		//cout<<"i ak ioi\n";
		if(m>=0){
			ans++;
		//	cout<<"omg\n";
		}
	}
	if(ans==n)cout<<n;
	else if(ans==0)cout<<0;
	else cout<<ans+1;
}/*
5 200
0 100 200 300 400*/