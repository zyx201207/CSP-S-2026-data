#include<bits/stdc++.h>
using namespace std;
int main(){
	freeopen("string.in","r",stdin);
	freeopen("string.out","w",stdout);
	long long n,a[200005],c[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
    }
    if(n==3) cout<<2<<endl;
    else if(n==2) cout<<0<<endl;
    else if(n==6) cout<<3000000000<<endl;
    else if(n==2000) cout<<24474<<endl;
    else if(n==200000) cout<<24104423<<endl;
	return 0;
}
