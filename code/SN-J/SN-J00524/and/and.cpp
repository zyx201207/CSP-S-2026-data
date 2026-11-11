#include <iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a,s[200000];
	s[0]=2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		s[i]=a;
	}
	for(int i=1;i<=n;i++){
		if(s[i]<s[i-1]){
			s[i-1]=s[i];
		}
	}
	cout<<s[0];
	return 0;
}
