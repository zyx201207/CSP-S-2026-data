#include<bits/stdc++.h>
using namespace std;
long long n,x;
char y;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=0;
	while(n--){
		cin>>x>>y;
		for(long long i=l;i<l+x;i++){
			a[i]=y;
		}
		l+=x;
	}
	long long sum=0;
	for(int i=0;(i+1)*2-1<l;i++){
		if(a[i]!=a[l-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
