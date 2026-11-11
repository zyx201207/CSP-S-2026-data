#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n=0,m=0;
	vector<long long>vec;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int t=0;
		cin>>t;
		vec.push_back(t);
	}
	cout<<n<<" "<<m<<" "<<m<<" ";
	return 0;
}

