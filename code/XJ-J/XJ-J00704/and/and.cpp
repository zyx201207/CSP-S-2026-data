#include<bits/stdc++.h>
using namespace std;
long long p[200005],c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		
	}
	p[0]=1;
	for(int i=1;i<=31;i++){
		p[0]=p[0]*2;
		
	}
	p[0]-=1;
	sort(c+1,c+n+1);
	for(int i=1;i<=m;i++){
		p[i]=c[1];
	}
	for(int i=2;i<=n;i++){
		for(int j=m;j>=1;j--){
			p[j]=max(p[j],p[j-1]&c[i]);
		}	
	}
	cout<<p[m];

}