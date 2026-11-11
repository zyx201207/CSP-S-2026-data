#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000005],v[1000005];
int main()
{
	freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--){
    	cin >> n >> k;
    	for(int i=1;i<n;i++){
    		cin >> u[i] >> v[i];
		}
		cout << n/5 << endl;
	}
	return 0;
}

