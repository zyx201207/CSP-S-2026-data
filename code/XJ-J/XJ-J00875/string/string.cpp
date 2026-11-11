#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,n,i,j,s=0;
	char c[10000];
	vector<char> num;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a>>c[i];
		for(j=1;j<=a;++j){
			num.push_back(c[i]);
		}
	}
	n=num.size();
	for(i=1;i<=(n-1)/2;++i){
		if(num[i-1]!=num[n-i]) s++;
	}
	cout<<s;
	return 0;
}