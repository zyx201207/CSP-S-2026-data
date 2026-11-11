#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,j,k) for(int i=(j);i<=(k);i++)
using namespace std;
const int Mxn=1010;
int c,n,m,d,q;
int w[Mxn],k;
int f[Mxn][Mxn];
int a[Mxn],t[Mxn];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++)scanf("%d",&w[i]);
	for(int i=1; i<=n; i++) {
		scanf("%d",&k);
//		cout<<"K:"<<k<<endl;
		for(int l=1; l<=k; l++) {
			cin>>a[l]>>t[l];
//			cout<<"a[l]"<<a[l]<<"\nt[l]"<<t[l]<<endl;
		}
		for(int l1=1; l1<=k; l1++) {
			for(int l2=l1; l2<=k; l2++) {
				if(l1==l2) {
					f[a[l1]][a[l2]]=0;
					continue;
				}
				f[a[l1]][a[l2]]=f[a[l2]][a[l1]]=Min(f[a[l1]][a[l2]],t[l1]+t[l2]);
				/*L(ii,1,m) {
					L(ij,1,m) {
						cout<<f[ii][ij]<<" ";
					}
					cout<<endl;
				}
				cout<<endl<<endl;*/
			}
		}/*
		L(ii,1,m) {
			L(ij,1,m) {
				cout<<f[ii][ij]<<" ";
			}
			cout<<endl;
		}*/
	}
	L(k,1,m)L(i,1,m)L(j,1,m)f[i][j]=Min(f[i][j],f[i][k]+f[k][j]);
	/*L(ii,1,m) {
		L(ij,1,m) {
			cout<<f[ii][ij]<<" ";
		}
		cout<<endl;
	}*/
	while(q--){
		int x=0,y=0;
		cin>>x>>y;
		cout<<(f[x][y]+w[x]+w[y])<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}




//   O(m^3)    32
