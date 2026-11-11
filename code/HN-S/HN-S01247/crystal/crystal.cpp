#include<bits/stdc++.h> 
using namespace std;
long long n,m,ans,da;
int a[999999];
int dai(int y){
	int x=0;
	for(int i=1;i<=y;i++){
		x+=a[y]-a[i];
	}

	return x;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		da=dai(i);
		if(da<=m){
			ans++;
		}
		else{
			break;
		}
	}

	cout<<ans;
	return 0;
}
