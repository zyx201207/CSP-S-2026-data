#include<bits/stdc++.h>
using namespace std;
long long n,a,s=1,sum=0;
char b[20000005];
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            b[s]=c;
            s++;
        }
	}
	for(int i=1;i<=s-1;i++){
        if(b[i]!=b[s-i]) sum++;
	}
	cout<<sum/2;
		return 0;
	}
