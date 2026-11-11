#include<bits/stdc++.h>
using namespace std;

int a[500005],s[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int mx=-1;
    for(int i=2;i<=n;i++){
    	s[i]+=s[i-1]+(a[i]-a[i-1])*(i-1);
//    	d[i]=s[i]-s[i-1];
	}
    for(int i=1;i<=n;i++){
    	if(s[i]<=m){
    		mx=max(mx,i);
		}
	}
	cout<<mx;
	return 0;
}