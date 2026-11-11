#include <bits/stdc++.h>
using namespace std;
long long c=0,sum=0,f=0;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	char a[200000],b[200000];
	cin>>n;
	long long s[n];
	for(long long i=0;i<n;i++){
		cin>>s[i];
		cin>>a[i];
		c+=s[i];
		for(long long j=0;j<s[i];j++){
			b[f]=a[i];
			f++;
		}
    }
    for(long long i=0;i<c;i++){
    	if(b[i]!=b[c/2-i]){
    		sum++;
        }
        if(i==c/2){
        	break;
		}
	}
	cout<<sum;
	return 0;
}
