#include<bits/stdc++.h>
using namespace std;
long long n,m,d[200005],ans=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	for(long long i=1;i<=n;i++)cin>>d[i];
	sort(d+1,d+1+n,cmp);
	ans=d[1];
	for(long long i=2;i<=m;i++){
		ans&=d[i];
	}
	cout<<ans;
	return 0;
}
