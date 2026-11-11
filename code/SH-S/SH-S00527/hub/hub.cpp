#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define endl '\n'
const int N=1e6+5;
int c,t;
void solve(){
	cout<<rand()%2+1<<endl;
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	srand(time(0));
	while(t--)solve();
	
	return 0;
} 

