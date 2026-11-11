#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=0;
	int m=0;
	cin>>n>>m;
	vector <int>vec;
	for(int i=0;i<n;i++){
		int t=0;
		cin>>t;
		vec.push_back(t);
	}
	for(int i=1;i<=m;i++){
		if(i==vec.back()){
			cout<<vec.size()<<" ";
		}else{
			cout<<vec.size()-i<<" ";
		}
	}
	return 0;
} 
