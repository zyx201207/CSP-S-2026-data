#include<bits/stdc++.h>
using namespace std;
int w[5*100],a[500][5*10],t[500][5*100],x[100],y[100];int k[500];
int c,n,m,d,q;
int search(int x,int y){
	int beg[2],end[2];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x){
				beg[0]=i,beg[1]=j;
			}
			if(a[i][j]==y){
				end[0]=i,end[1]=j;
			}
		}
	}
	if(beg[0]==end[0]){
		int sum=0;
		if(beg[1]>end[1])swap(beg[1],end[1]);
		for(int i=beg[1];i<=end[1];i++){
			sum+=t[beg[0]][i];
		}
		return sum;
	}
//	for(int i=0;i<=k[beg[0]];i++){
//		for(int j=0;j<=k[end[0]];j++){
//			if(a[beg[0]][i]==a[end][0][i]){
//				
//			}
//		}
//	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[m];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){ 
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		int time=w[x[i]]+w[y[i]];
		cout<<time+search(x[i],y[i]);
	}
//	fclose(stdin);fclose(stdout);
	return 0;
}

