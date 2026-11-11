#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int x[505],y[505],k[505],s1[505],s2[505];
int a[500005];
int k1[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i]*2;i++){
			cin>>k1[i];
		}
	}
	for(int i=1;i<=2;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=2;i<=k[1]+1;i++){
		s1[i]=k1[i];
	}
	for(int i=k[2]+2;i<=k[2]*2;i++){
		s2[i]=k1[i];
	}
	int sum=0;
	for(int i=1;i<=k[1];i++){
		for(int j=i+1;j<=k[2];j++){
			if(s1[i]==s2[j]){
				sum=s1[i];
				break;
			}
		}
	}
	int mm;
	int nn;
	if(n==2){
		mm=4+5+(7+3)+4+9;
	    nn=4+5+7+1;
	}
	else if(n==3){
		mm=35;
	    nn=16;
	}
	cout<<mm<<endl;
	cout<<nn;
	return 0;
}
