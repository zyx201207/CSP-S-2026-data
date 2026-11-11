#include<bits/stdc++.h>
using namespace std;
const long long MAX=2000000000000009;
char arr[MAX];
long long l=0,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		for(long long i=l+1;i<=l+a;i++){
			arr[i]=c;
		}
		l+=a;
	}
	l=(l+1)/2;
	long long dif=0;
	for(long long i=1;i<=l;i++){
		if(arr[i]!=arr[l-i+1]){
			dif++;
		}
	}
	cout<<dif;
	return 0;
}
