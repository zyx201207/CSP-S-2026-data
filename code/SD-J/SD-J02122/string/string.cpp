#include <iostream>
#include <string>
using namespace std;
int n;
int a;
char b;
string o;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a>>b;
		for (int i=1;i<=a;i++){
			o+=b;
		}
	}
	long long ans=0;
	for (int i=0;i<o.size()/2;i++){
		if (o[i]!=o[o.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
