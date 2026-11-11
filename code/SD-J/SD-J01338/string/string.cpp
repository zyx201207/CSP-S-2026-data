#include<bits/stdc++.h>
using namespace std;
long long n;
void s(){
	cin>>n;
	string a[n+10],d[n+10];
	for(int i=1;i<=n;i++){
		int b;
		char c;
		cin>>b>>c;
		for(int j=1;j<=b;j++){
			a[j]=c;
		}
		for(int j=b;j>1;j--){
			d[j]=c;
		}
		cout<<2;
	}
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	s();
	return 0;
} 
