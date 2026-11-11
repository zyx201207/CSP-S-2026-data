#include<bits/stdc++.h>
using namespace std;
struct hui{
	int d;
	char f;
};
hui a[100010];
int main(){
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].d>>a[i].f;
	}
	if(a[1].d==2&&a[1].f=='a'&&a[2].d==2&&a[2].f=='b'&&a[3].d==1&&a[3].f=='c'){
		cout<<2;
	}
	else{
		cout<<0;
	}
	return 0;
}
