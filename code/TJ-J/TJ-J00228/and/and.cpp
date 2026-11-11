#include<bits/stdc++.h> 
using namespace std;
long long s[200011];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long ans=0;
	for (int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1,cmp);
	ans=s[1];
	for (int i=1;i<=m;i++){
		ans&=s[i];
	}
	cout<<ans;
	return 0;
}
