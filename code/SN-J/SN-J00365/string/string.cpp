#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector <char> w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char p;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>p;
		for(int j=0;j<a;j++){
			w.push_back(p);
		}
	}
	int sz=w.size();
	int sum=0;
	for(int i=0;i<sz/2;i++){
		if(w[i]!=w[sz-1])sum++;
	}
	cout<<sum<<endl;
	return 0;
}
