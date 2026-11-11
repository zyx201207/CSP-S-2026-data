#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum =0;
	cin>>n;
	string a;
	for(long long i=0;i<n;i++){
		long long b;
		char c;
		cin>>b>>c;
		while(b--){
			a.push_back(c);
		}
		for(int i=0,j=a.size()-1;i<a.size();i++){
			if(j !=1&&a[i]!=a[j]){
				a[j] = a[i];
				sum++;
			}
			if(j==i){
				break;
			j--;
		}
	
}
			cout<<sum;
		}
return 0;
}
