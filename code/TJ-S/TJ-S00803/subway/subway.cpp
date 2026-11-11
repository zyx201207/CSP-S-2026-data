#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100; 
int c,n,m,d,q;
int w[1001],num[601][601],t[601][601],a[N][N],l[601];
int main(){
	freopen("subway.in","r",stdin);	
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>num[i][j]>>t[i][j];
			a[num[i][j-1]][num[i][j]]=t[i][j]+w[num[i][j-1]]+w[num[i][j]]+t[i][j-1];
		}
	}
	for(int i=1;i<=q;i++){
		int l,r,cnt=0;
		cin>>l>>r;
		for(int j=1;j<=n;j++){
			if(num[i][j]==num[i][l]) cout<<a[i][l]<<endl;
		}
	}
	return 0;
} 
