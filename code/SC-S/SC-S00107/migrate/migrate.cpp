#include<bits/stdc++.h>//3题 
const int N=1e6+1; 
using namespace std;
#define ll long long

signed main(){
	freopen("migrate","r",stdin);
	freopen("migrate","w",stdout);
	int c,t;
	cin >> c >> t;
	for (int iiiii=1;iiiii<=t;iiiii++){
		int n,d,stp=0;
    	cin >> n >> d;
		ll x[N];
		for (int i = 1;i <= n;i++) cin >> x[i];
	    if(c==11||c==12)//等差 
		{
	    	if (x[3]-x[2]<=d){
	    		cout << n-3;
			}
			else{
				cout << 0;
			}
		}
	}
	return 0;
} 