#include<bits/stdc++.h>
using namespace std;
int a[1001]={ },b[1001]={ },b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0,ans=0;
    string c,s;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	cin>>b[i];
    	if(c[i]!=c[i-1] && i!=1){
    		b=1;
		}
		cnt+=a[i];
	}
	if(b==0){
		cout<<"0";
		return 0;
	}
	cout<<cnt;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[i][j]=c[i];
		}
	}
    return 0;
}
