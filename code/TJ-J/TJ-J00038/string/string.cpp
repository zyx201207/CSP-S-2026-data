#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    
	long long n,j=0;
	cin>>n;
//	cout<<n<<endl;
	string a;
	for(long long i=1;i<=n;i++){
		int b;
		string c;
		cin>>b;
		cin>>c;
//		cout<<b<<"b "<<c<<"c ";
		for(long long j=1;j<=b;j++){
			a+=c;
//			cout<<a<<"a ";
		}
//		cout<<endl;
	}
//	cout<<a<<endl;
	for(long long i=0;i<=a.size()/2-1;i++){
		if(a[i]!=a[a.size()-i-1]) j++;
//		cout<<i<<" "<<a.size()-i-1<<endl;
	}
	cout<<j;
	
	return 0;
}
