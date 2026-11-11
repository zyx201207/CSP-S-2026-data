#include<bits/stdc++.h>
using namespace std;

const int N=510,M=500010;
int c,m,n,d,q;
int a[N],s[N][N];

struct Node{
	int id,time,nums;
} sub[M];  

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>sub[i].id>>sub[i].time>>sub[i].nums;
		for(int j=1;j<=m;j++){
			s[i][j]=min(s[i-1][j],s[i][j-sub[i].time]+w[i]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<s[i][j];
		}
	}
	return 0;
}
