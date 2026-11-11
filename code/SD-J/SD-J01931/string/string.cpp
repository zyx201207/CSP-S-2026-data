#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
    	int x;
    	char y;
    	cin>>x>>y;
    	for(int j=1;j<=x;j++){
    		s=s+y;
		}
	}
	int ans=0,len=s.size();
	for(int i=1;i<=len;i++){
		if(a[i]=a[len+i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
