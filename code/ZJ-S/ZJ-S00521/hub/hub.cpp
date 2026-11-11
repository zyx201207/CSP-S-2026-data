#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
		}
		int m=(n-1)/2;
		if(k==1)cout<<(m+1)/2;
		else if(k==n)cout<<0;
		else if(k>=m)cout<<1;
		else{
			k-=m%3;
			if(k<0)cout<<m/3;
			int cnt=m/3;
			while(k>=3){
				k-=3;
				cnt--;
			}
			cout<<cnt;
		}
		cout<<'\n';
	}
	return 0;
}
/*
调了1e18年了还没过 没招了
*/