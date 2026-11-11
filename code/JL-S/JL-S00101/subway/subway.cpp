#include<bits/stdc++.h>
using namespace std;
long long w[1000010];
long long k[10010];
long long a[5010][5010];
long long t[5010][5010];
long long destx[5005];
long long desty[5005];
long long f[500];
long long x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,xi,sum=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	long long tot=0;
	for(int T=1;T<=q;T++){
		cin>>x>>y;
		if(x==y){
			cout<<0<<endl;
			break;
		}
		tot=w[x]+w[y];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					tot+=t[i][j];
					xi=i;
				}else if(a[i][j]==y){
					sum++;
					destx[sum]=i;
					desty[sum]=j;
				}
			}
		}
		bool flag=false;
		for(int j=1;j<=k[xi];j++){
			if(a[xi][j]==y){
				flag=true;
				tot+=t[xi][j];
				cout<<tot<<endl;
				break;
			}	
		}
		for(int j=1;j<=k[xi];j++){
			if(!flag){
				bool flag2=false;
				if(sum>1){
					for(int dfg=1;dfg<=sum;dfg++){
						for(int dfj=1;dfj<=k[destx[dfg]];dfj++){
							if(a[destx[dfg]][dfj]==a[xi][j]){
								flag2=true;
								tot+=t[xi][j]+t[destx[dfg]][dfj]+t[destx[dfg]][desty[dfg]];
								break;
							}
						}
						if(flag2){
							cout<<tot<<endl;
							break;
						}
					}
					break;
				}else{
					for(int dfj=1;dfj<=k[destx[sum]];dfj++){
						if(a[destx[sum]][dfj]==a[xi][j]){
							flag2=true;
							tot+=t[xi][j]+t[destx[sum]][dfj]+t[destx[sum]][desty[sum]];
							break;
						}
					}
					if(flag2==true){
						cout<<tot<<endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}
