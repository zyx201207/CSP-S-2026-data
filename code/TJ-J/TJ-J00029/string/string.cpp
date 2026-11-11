#include <iostream>
#include <cstdio>
using namespace std;

long long n,a[200005],r=0,l=1,cnt=0;
string c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string t=" ";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			t+=c[i];
		}
		r+=a[i];
	}
	while(true){
		if(r%2==0){
			if(l>r) break;
		}
		else{
			if(r==l) break;
		}
		if(t[l]!=t[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
