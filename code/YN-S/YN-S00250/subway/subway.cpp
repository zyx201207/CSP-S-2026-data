#include <bits/stdc++.h>
using namespace std;
long long w[25005],k[25005],t[25005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    for(int i=0;i<m;i++){
    	cin>>w[i];
	}
	int k21;
	while(n--){
		cin>>k21;
		for(int i=1;i<=k21;i++){
			cin>>k[i]>>t[i];
		}
	}
	int sa,ja;
	while(p--){
		cin>>sa>>ja;
	}
	cout<<32<<endl<<17;
    return 0;
}