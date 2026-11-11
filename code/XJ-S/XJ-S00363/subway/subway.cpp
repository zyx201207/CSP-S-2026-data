#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int sbcnm=17;
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	while (e--){
		cout<<abs(sbcnm*(b-e));
	}
	return 0;
}





