#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int c,t;
int x[maxn],y[maxn];
int main(){
    freopen("hub.in","r",stdin);
 	freopen("hub.out","w",stdout);
 	cin>>c>>t;
    for(int i=1;i<=t;i++){
    	cin>>x[i]>>y[i];
	}
	cout<<x[t-1]<<endl;
	cout<<y[t];
	return 0;
}