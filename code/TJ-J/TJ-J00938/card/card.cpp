#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	string a,b="";
	cin>>n>>m;
	getline(cin,a);
	for(int i=2;i<n;i++){
		for(int j=1;i<=n;j++){
			if(a[i]==a[i-j]){
				b+=a.erase(a[i-j],i-1);
				b+=a[i+1];
			}
		}
	}
	cout<<b;
	return 0;
}
