#include<bits/stdc++.h> 
using namespace std;
int n,m;
long long a[200005];
long long x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	x = a[n];
	for(int i = n-1;i >= m;i--){
		x &= a[i];
	}
	cout<<x;
}
