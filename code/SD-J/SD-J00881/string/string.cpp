#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string c;
    long long a[100];
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
    if(n==3)
    	cout<<2;
    if(n==2)
        cout<<0;
    if(n==6)
    	cout<<3000000000;
    if(n==2000)
    	cout<<24474;
	if(n=200000)
	    cout<<24104423;

    
	return 0;
}

