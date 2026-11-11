#include<bits/stdc++.h>
using namespace std;
struct s{ 
	int p[501];
	int t;
	int w;
};
int c,n,m,d,q;
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
s s[500]={};
for(int i=0;i<m;i++){
	cin>>s[i].w;
}
for(int i=1;i<=n;i++){
	int k;
	cin>>k;
	for(int j=1;j<=k;j++){
		int awa;
		cin>>awa;
		s[awa].p[i]=j;
		cin>>s[awa].t;
	}
}
cout<<s[4].p[1];	
return 0;
}

