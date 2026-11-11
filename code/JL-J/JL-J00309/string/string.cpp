#include <bits/stdc++.h>
using namespace std;
long long a[100000005];
string  c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n;
	long long cnt=0;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
    string s;
    for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[j]=c[i];
			cout<<s[j];
		}
	}
	for(int i=1,j=cnt;i<cnt/2,j>cnt-cnt/2;i++,j--){
		if(s[i]!=s[j]){
				sum++;
			}
	}
	cout<<sum;
    return 0;
}
