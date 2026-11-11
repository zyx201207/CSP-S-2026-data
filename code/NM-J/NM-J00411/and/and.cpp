#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool fun(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0;
	int m=0;
	cin>>n>>m;
	vector <int> vec;
	for(int i=0;i<n;i++){
		int t=0;
		cin>>t;
		vec.push_back(t);
	}
	sort (vec.begin(),vec.end(),fun);
	int x=vec[0];
	for(int i=1;i<m;i++){
		x=x&vec[i];
	}
	cout<<x;
	
	return 0;
} 
