#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool fun1(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=0;
	long long m=0;
	cin>>n>>m;
	vector<long long>vec;
	for(long long i=0;i<n;i++){
		long long a=0;
		cin>>a;
		vec.push_back(a);
	}
	sort(vec.begin(),vec.end(),fun1);
	cout<<vec[m-1];
	return 0;
}
