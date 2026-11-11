#include<bits/stdc++.h>
using namespace std;
int a[200002];
bool cmp(int a,int b){
	return a>b;
}
bool chl(int x){
	while(x>1){
		if(x%2!=0){
			return true;
		}
		x/=2;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int ans=2147483647;
	bool f=false;
	for(int i=1;i<=m;i++){
		if(chl(a[i]) || i==m || f){
			ans&=a[i];
		}
		else{
			if((m+1)>n){
				ans&=a[i];
				f=true;
			}
			else{
				m++;
			}
		}
	}
	cout<<ans;
	return 0;
}
