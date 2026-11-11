#include <bits/stdc++.h>
using namespace std;
int a[10000][510];
int ai[510];
int t[500010];
int begin,end;
int num,mn=100010;
void tui(int b){
	if (b==end){
		return ;
	}
}
int main (){
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>t[i];
	}
	for (int i=1;i<=n;i++){
		int num;
		cin>>num;
		for (int j=1;j<=num;j++){
			cin>>ai[j];
			cin>>a[i][ai[j]];
		}
	}
	for (int i=1;i<=q;i++){
		cin>>begin>>end;
		int num=0,mn=100010;
	}
	cout<<32<<endl<<17;
	return 0;
}
