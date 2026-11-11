#include<iostream>
using namespace std;
string a;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,z=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int j;
		cin>>j>>x;
		z+=j;
		while(j--){
			a+=x;
		}
	}

	long long ans=0;
//	if(z%2==0){
//		z--;
//
//	}
	for(int i=0;i<z/2;i++){

		if(a[i]!=a[z-i-1]){
				ans++;
		}	
	}		
	cout<<ans;
	return 0;
}
