#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[100],x;
int main(){
	freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	x=a[1]&a[2];
	for(int i=2;i<=m;i++){
        x=x&a[i];
	}
}
