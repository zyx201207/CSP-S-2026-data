#include <bits/stdc++.h>
using namespace std;
int a[200000300];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	long long n,q=0,l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l+=a[i];
		cin>>c;
		for(int j=0;j<a[i];j++){
			s+=c;
		}
	}
	int he=0,i=0,j=l-1;
	while(i<=j){
		if(s[i]!=s[j]){
			he++;
		}
		i++;
		j--;
	}
	cout<<he;
	return 0;
}
