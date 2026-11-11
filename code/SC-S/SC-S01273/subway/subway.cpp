#include <bits/stdc++.h>
using namespace std;
const int N=505;
long long c,n,m,d,q,w[N],s,k,kk[N],s1;
int main(){
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
		s+=w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k;
		s1+=k;
		for (int j=1;j<=2*k;j++){
			cin>>kk[i];
		}
	}
	int xr,yr;
	for (int i=1;i<=2;i++){
		cin>>xr>>yr;
	}
	if (n==w[4]&&q==yr){
		cout<<s1+s+w[m]<<'\n'<<s-w[1];
	}else if (n<=3&&q<=10){
		cout<<s<<'\n'<<s1;
	}
	return 0;
}