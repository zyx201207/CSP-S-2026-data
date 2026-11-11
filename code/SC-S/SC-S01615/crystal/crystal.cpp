#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	int a[n];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(abs(a[1]-a[2])>m){
			cout<<1;
			return 0;
		}else{
			cout<<2;
			return 0;
		}
	}
	
	if(n==3){
		int x;
		x=max(a[1],a[2],a[3]);
		if((x-a[1]+x-a[2]+x-a[3])<=m){
			cout<<3;
			return 0;
		}else if((abs(a[1]-a[2])||abs(a[3]-a[2])||abs(a[1]-a[3]))<=m){
			cout<<2;
			return 0;
		}else{
			cout<<1;
			return 0;
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}