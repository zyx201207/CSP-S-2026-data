#include<iostream>
#include<cstring>
using namespace std;
long long n,a[200005],ans,size;
string c[200005],stri;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long ai;
		string ci;
		cin>>ai>>ci;
		a[i]=ai;
		c[i]=ci;
		size+=ai;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			stri+=c[i];
		}
	}
	for(int i=0;i<size/2;i++){
		if(stri[i]!=stri[size-i-1]) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


