#include <iostream>
using namespace std;
string s;
int a[200005],n,b=1,k;
char c;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a[i]>>c;
	for(int j=1;j<=a[i];j++){
		s[b]=c;
		b++;
	}
    }
    b--;
    for(int i=1;i<=b;i++){
    if(s[i]!=s[b+1-i]){
    	s[b+1-i]=s[i];
    	k++;
	}
	}
	cout<<k;
	return 0;
}
