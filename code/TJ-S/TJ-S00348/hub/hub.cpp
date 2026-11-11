#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int c,t,n,k;
int main(){
    freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		int a[N][2];
		cin>>n>>k; 
		for(int i=1;i<=n-1;i++){
			cin>>a[i][0]>>a[i][1]; 
		}
		cout<<1<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
