#include<bits/stdc++.h>
using namespace std;
int fun(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=0,m=0;
	int maxn=0; 
	int k=0;
	cin>>n>>m;
	vector<long long>vec;
	for(long long i=0;i<n;i++){
		long long t=0;
		cin>>t;
		vec.push_back(t);
	}
	sort(vec.begin(),vec.end(),fun);
	cout<<vec[m] and vec[m-1];
	return 0;
}

