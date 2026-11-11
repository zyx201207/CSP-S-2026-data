#include <bits/stdc++.h>
using namespace std;
int n,m,tot;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(i==1)tot=x;
        else tot&=x;
    }
    cout<<tot;
	return 0;
}
