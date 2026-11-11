#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[1000],bj[1000][1000];
	for(int i=1;i<=m;i++){
		cin>>a[i];
		for(int j=1;j<=m;j++){
			bj[i][j]=0x3f;
		}
	}
	for(int i=0;i<n;i++){
		int k,a1=0,t1;
		cin>>k;
		for(int j=0;j<k;j++){
			int a2=a1,t2=t1;
			cin>>a1>>t1;
			if(a2!=0){
				bj[a2][a1]=t2+t1;
			}
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cout<<bj[x][y]+a[x]+a[y];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
