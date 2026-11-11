#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int n,m;
ll a[maxn];
//good bye!I love OI.
//ei??yang li ju ran quan guo le??
//luogu UID:2020970,Can you see me?
ll ans;
bool cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	bool flag=true;
	for(int i=n-1;i>=n-m;i--){
        if(flag) ans=a[i];
        else an4s&=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
