#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500010],b[500010],c[300010],t;
bool f[300010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!f[a[j]]){
				f[a[j]]=1;
				t++;
				b[t]=a[j];
			}
			else while(b[t]!=a[j]){
					 f[b[t]]=0;
					 t--;
				 }
		}
		for(int j=1;j<=t;j++){
			f[b[j]]=0;
			c[b[j]]++;
		}
		t=0;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}