#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,m,a[N],ans1,ans2;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans1=a[1];
	for(int i=1;i<=m;i++){
		ans1&=a[i];
	}
	if(m+1>n) ans2=-1e9;
	else{
		ans2=a[2];
	    for(int i=2;i<=m+1;i++){
		    ans2&=a[i];
	    }
	}
	cout<<max(ans1,ans2)<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
