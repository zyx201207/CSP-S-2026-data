#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N];
struct node{
	int next,v;
}head[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=q;i++){
		cout<<m+1<<endl;
	}
	return 0;
}