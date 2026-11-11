#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
long long n,x,s=0;
char d;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	cout.tie(false);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>x>>d;
		for(int i=1; i<=x; i++){
			a+=d;
		}
	}
	for(int i=0,j=a.size()-1; i<a.size()/2;i++,j--){
		if(a[i]!=a[j]){
			s++;
		}
	}
	cout<<s;
	return 0;
} 
