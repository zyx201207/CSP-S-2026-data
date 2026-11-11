#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20005],map1[15000][15000],t=0;
long long ttt(long long x,long long y){
	long long b[200005],c[200005],ans1=0;
	long long x1=0,y1=0;
	while(x!=0){
		x1++;
		b[x1]=x%2;
		x/=2;
	}
	while(y!=0){
		y1++;
		c[y1]=y%2;
		y/=2;
	}
	for(int i=max(x1,y1);i>=1;i--){
		if(b[i]==1&&c[i]==1){
			ans1=ans1*2+1;
		}else{
			ans1=ans1*2;
		}
	}
	return ans1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out" ,"w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		map1[i][1]=max(map1[i-1][i],a[i]);
	}
	for(long long j=2;j<=m;j++){
		t=j-1;
		for(long long i=1;i<=n;i++){
			if(t<j){
				if(map1[i-1][j]<ttt(map1[i][j-1],a[i])){
					t++;
				}
				map1[i][j]=max(map1[i-1][j],ttt(map1[i][j-1],a[i]));
			}else{
				map1[i][j]=map1[i-1][j];
			}
		}
	}  
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<map1[j][i]<<" ";
		}
		cout<<endl;
	}
	cout<<map1[n][m];
	return 0;
}
