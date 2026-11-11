#include<bits/stdc++.h>
using namespace std;
long long n,m,t,p,q,s,a[200005],k[35],f[35][200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];t=a[i];p=1073741824;q=30;
		while (t>0){
			if (t>=p){
				t-=p;
				f[q][++k[q]]=a[i];
			}p/=2;q--;
		}
	}for (int i=30;i>=1;i--) if (k[i]>=m){
		sort(f[i]+1,f[i]+k[i]+1);s=f[i][k[i]];
		for (int j=k[i]-1;j>=k[i]-m+1;j--) s=(s & f[i][j]);
		cout<<s;
		return 0; 
	}
}
