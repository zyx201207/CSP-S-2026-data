#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>v;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	int deshu=0;
	int zhi2=0;
	for(int i=0;i<n;i++){
		int zhi1=v[i];
		while(v[i]!=0){
			zhi2=zhi2+zhi1%10;
			zhi1=zhi1/10;
		}
		if(zhi2>deshu){
			deshu=zhi2;
		}
	}
	cout<<zhi2<<endl;
	return 0;
}
