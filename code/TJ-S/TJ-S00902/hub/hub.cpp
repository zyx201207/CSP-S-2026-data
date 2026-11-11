#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		cout<<(n+k)/6;
	}
	return 0;
}
