#include<bits/stdc++.h>
using namespace std;

int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long m,n,a;
	vector <int> l;
	cin>> n>>m;
	cin>>l[n];
	for(int i=1;i<=pow(m,n);i++){
		a[i]=l[i]&l[i+1];
	}
	cout<<max(a[0],a[i])<<endl;
	return 0; 
}
