#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
struct node{
	int start;
	int end;
}r[MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("sucway.out","w",stdout);
	int c,n,m,d,q;
	int w[MAXN],a[505][MAXN],t[505][MAXN];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i=m;i++){
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int p=1;p<=q;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				cin>>a[i][j]>>t[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r[p].start>>r[p].end;
		}
		int sum=w[r[p].start]+w[r[p].end];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				for(int f=j+1;f<=k;f++){
					if(a[i][j]==r[p].end&&a[i][f]==r[p].start){
						sum+=a[i][r[p].end]+a[i][r[p].start];
					}
				}	
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
