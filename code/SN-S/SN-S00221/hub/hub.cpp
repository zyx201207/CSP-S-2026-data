#include<bits/stdc++.h>
#define ll long long
#define vi void
#define endl '\n'
#define pii pair<int,int>
using namespace std;

mt19937 rd(time(0));
int c,n;

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n;
	while(n--) {
		if(c<=6) {
			cout<<rd()%10<<endl;
		} else if(7<=c<=10) {
			cout<<rd()%50<<endl;
		} else if(11<=c<=12) {
			cout<<rd()%500<<endl;
		} else if(13<=c<=14) {
			cout<<rd()%20000<<endl;
		} else {
			cout<<rd()%50000<<endl;
		}
	}
	return 0;
}

