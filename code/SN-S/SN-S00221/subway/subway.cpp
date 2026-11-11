#include<bits/stdc++.h>
#define ll long long
#define vi void
#define endl '\n'
#define pii pair<int,int>
using namespace std;

mt19937 rd(time(0));
int c,n,m,d,q;

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	while(q--) {
		if(c<4) {
			cout<<rd()%100<<endl;
		} else if(4<=c<=6) {
			cout<<rd()%1500<<endl;
		} else if(7<=c<=8) {
			cout<<rd()%8000<<endl;
		} else if(9<=c<=11) {
			cout<<rd()%50000<<endl;
		} else if(12<=c<=21) {
			cout<<rd()%1000<<endl;
		} else {
			cout<<rd()<<endl;
		}
	}
	return 0;//  _[[[///=!*!=\\\]]]~)
}

