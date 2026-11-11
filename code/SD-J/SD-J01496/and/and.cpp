#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],q,mx,e,cnt=1,ans,tt=1;
string sa;
char sw[200005][35],d='1';
bool y=0,ym=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>mx){
			mx=a[i];
		}
	}
	if(m==1){
		cout<<mx;
	}
}
