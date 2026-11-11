#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
string b[200005];
long long l,h;
int sa;
string k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int q=1;q<=n;q++){
		cin>>a[q]>>b[q];
		for(int j=1;j<=a[q];j++){
			k+=b[q];
			l+=a[q];
		}
	}
	if(l%2==0){
		l/=2;
	}
	else{
		l--;
		l/=2;
	}
	for(int i=0;i<l;i++){
		if(k[i]!=k[l+1-i]){
			h++;
		}
	}
	cout<<h;
	return 0;
}
