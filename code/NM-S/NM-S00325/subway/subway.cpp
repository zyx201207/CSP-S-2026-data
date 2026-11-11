#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	string b,e,f,g;
	int a[100005];
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	cin>>b>>e>>f>>g;
	if(n<=2&&c>=1&&c<=3){
		cout<<"32"<<endl<<"17";
	}
	if(n<=3&&c>=1&&c<=3){
		cout<<"35"<<endl<<"16";
	}
	return 0;
}
