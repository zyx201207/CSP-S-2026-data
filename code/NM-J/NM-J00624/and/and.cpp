#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,max=INT_MIN;
	vector<int> v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
		if(v[i]&m>max){
			v[i]=max;
		}
	}
	cout<<max;
	return 0;
}

