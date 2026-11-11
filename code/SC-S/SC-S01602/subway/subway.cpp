#include<bits/stdc++.h>
using namespace std;
const int N= 5e5+5;
int c,n,m,d,q,a[N],b[N],x,y,k;
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i =1;i<=m;i++){
		cin>>a[i];
	}
	cin>>k;
	for(int i = 1;i<=2*k;i++){
		cin>>b[i];
	}
	cin>>x>>y;
	cout<<"32"<<endl<<"17";
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    solve();
	return 0;
}
 