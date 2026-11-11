#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool cmp(int x,int y){
	if(x>y)return true;
	else return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans and a[i];
	}
	cout<<ans;
}
