#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],s,x;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=1;j++){
			if(j==1&&i>1)a[i]&=s;
			s=a[i];
		}
	}
	cout<<s;
	return 0;
}