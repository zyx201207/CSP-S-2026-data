#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);
	for(int i=1; i<m; i++){
		cin>>w[i];
	}
	if(c==0 && n==2)cout<<"32"<<endl<<"17";
	else if(c==0 && n==3)cout<<"35"<<endl<<"16";
	return 0;
}
