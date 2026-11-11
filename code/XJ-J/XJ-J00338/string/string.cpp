#include<bits/stdc++.h>
using namespace std;
int n;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long b;string c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b>>c;
		while(b--) a+=c;
	}
	int l=0,r=a.size()-1;
	int sum=0;
	while(l<r){
		if(a[l]!=a[r]) sum++;
		l++,r--;
	}
	cout<<sum;
	return 0;
}