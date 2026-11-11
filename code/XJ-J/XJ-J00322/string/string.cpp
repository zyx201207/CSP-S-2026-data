#include<bits/stdc++.h>
#include<string>
using namespace std;
int cut;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long n;
    cin>>n;
    string s;
    int a[n+1];
    char c[n+2];
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
    	for(int j=1;j<=a[i];j++){
    		s=s+c[j];
		}
	}
	for(int i=0;i<s.size()/2;i++){
		int l=s.size();
		if(s[i]!=s[l+1-i]){
			cut++;
		}
	}
	cout<<cut;
	return 0;
}