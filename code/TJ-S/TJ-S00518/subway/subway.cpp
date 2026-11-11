#include<iostream>
#include<cstdio>
using namespace std;
long long c,n,m,d,q,z[500005],k,o[505][505],b,a,t,x,y,p=1,sum;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>z[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			if(j==1){
				b=a;
				o[a][a]=t;
			}
			else{
				o[b][a]=t;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		sum+=z[x]+z[y];
		for(int j=1;j<=505;j++){
			sum+=o[j][p];
			p++;
			sum+=o[j][p];
			if(p==y){
				break;
			}
		}
		cout<<sum<<endl;
		sum=0;
		p=0;
	}
	return 0;
} 
