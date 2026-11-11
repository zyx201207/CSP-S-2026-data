#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n,m,a[100005];
string b[100005],l,c[100005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]!=0){
			b[i]+=a[i]%2+48;
			a[i]/=2;
		}
		for(int j=1;j<=n;j++){
			l=b[i];
			for(int z=l.size()-1;z>=0;z--){
				c[i]+=l[z];
			}
		}
		cout<<c[1];
		
 	}
	
	return 0;
}

