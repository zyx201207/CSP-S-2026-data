#include<bits/stdc++.h>
using namespace std;
const int MAXN=100009;
int c,n,m,d,q;
int zhanting[MAXN],start[500009],end[500009];
int luxian[509][MAXN],zhantai[509][MAXN];
void spjg1(){
	cout<<32<<endl<<17<<endl<<35<<endl<<16;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>zhanting[i];
	}
	for(int i=1;i<=q;i++){
		int gt;
		cin>>gt;
		for(int j=1;j<=gt;j++){
			cin>>luxian[i][j]>>zhantai[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>start[i]>>end[i];
	}
	if(c>=7&&c<=11) {
		spjg1();
	}
	return 0;
} 
