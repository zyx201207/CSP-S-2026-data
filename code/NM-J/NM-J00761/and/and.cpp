#include <bits/stdc++.h>
using namespace std;
bool fun1(int a,int b){
	return a>b; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=0,m=0;
	cin>>n>>m;
	vector<int>vec;
	for(long long i=0;i<n;i++){
		int p=0;
		cin>>p;
		vec.push_back(p);
			}
	sort(vec.begin(),vec.end(),fun1);
	cout<<vec[m-1];
	
	
	
	
	
	
	return 0;
} 
