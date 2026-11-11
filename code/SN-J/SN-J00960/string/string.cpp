#include <bits/stdc++.h>
using namespace std;
vector<string> s(2e5+5);
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int y;
		cin>>y;
		char t;
		cin>>t;
		for(int j=0;j<y;j++){
			s[l]=t;
			l++;
		}
	}
	int sum=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			s[l-i-1]=s[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
