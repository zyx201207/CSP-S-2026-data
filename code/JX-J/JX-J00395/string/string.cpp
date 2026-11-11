#include<bits/stdc++.h>
using namespace std;
string b;
string d;
long long n,m,k,tail,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
		cin>>m;
		k=k+m;
		cin>>b;
		for(int j=0;j<m;j++){
			d+=b;
		}
    }
	for(int i=0;i<=k/2-1;i++){
		if(d[i]!=d[k-1-i])
		    ans++;
	}
	cout<<ans;
}
