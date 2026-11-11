#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[200005];
	string c;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=a[i];i++){
		    s+=c[i];	
		    if(s[i]==a[s.size()-i+1]){
		    	cout<<0;
			}
		}
	}
	return 0;
}
