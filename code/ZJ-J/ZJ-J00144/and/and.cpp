#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s,g;
bool p[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30;i>=0;i--){
		if(!g){
			int ws=0;
			for(int j=1;j<=n;j++)ws+=((a[j]>>i)&1);
			if(ws>=m){
				s+=(1<<i);
				g=1;
				for(int j=1;j<=n;j++)p[j]=((a[j]>>i)&1);
			}
		}
		else{
			int ws=0;
			for(int j=1;j<=n;j++)ws+=(p[j]&&((a[j]>>i)&1));
			if(ws>=m){
				for(int j=1;j<=n;j++)p[j]=(p[j]&&((a[j]>>i)&1));
				s+=(1<<i);
			}
		}
	}
	cout<<s;
	return 0;
}
