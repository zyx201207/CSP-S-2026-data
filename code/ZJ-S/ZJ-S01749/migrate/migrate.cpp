#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[2222222];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d=-1,flag=1,D;
		cin>>n>>D;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			if(i==2)d=arr[i]-arr[i-1];
		}
			int step=D/d;
			if(step>=n)cout<<0<<endl;
			else if(2*step>=n){
				cout<<(n-step)*(n-step-1)/2<<endl;
			}else{
				cout<<(2*n-3*step)*(step-1)/2<<endl;
			}
			
		
	}
}
/*O(2^n)+te pan
DESTRUCTION 3,2,1 AT 17.3
                []]
                []]
                []]
---             []]
            ---
        ---
    ---
---             ---
            ---
        ---
    ---
---             ---
            ---
        ---
    ---
---             ---
*/
