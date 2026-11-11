#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,t[10000],l[10000],k[10000],s[10000],o[10000],z=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			cin>>l[j]>>k[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s[i]>>o[i];
	}
	for(int i=0;i<10000;i++){
		z+=t[i];
		z+=l[i];
		z+=k[i];
	}
	cout<<z;
	return 0;
}












































