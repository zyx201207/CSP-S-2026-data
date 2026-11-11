#include <iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long int a[n],q=0,p=0,x=0;
	char c[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		q+=a[i];
	}
	char s[q+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s[p]=c[i];
			p++;
		}
	}
	for(int i=0;i*2<q;i++){
		if(s[i]!=s[q-i-1]){
			x++;
		}
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
