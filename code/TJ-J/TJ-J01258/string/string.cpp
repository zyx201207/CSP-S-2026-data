#include <iostream> 
#include <string> 
using namespace std;
string s;
char a;
int b,c,n,x=0;
int main(){
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>a;
		for(int j=1;j<=b;j++){
			s[c]=a;
			c++;
		}
	}
	for(int i=1;i<c;i++){
		if(s[i] != s[c-i]){
			x++;
		}
	}
	cout<<x;
	return 0;
}
