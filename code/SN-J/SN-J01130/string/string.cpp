#include<bits/stdc++.h>
using namespace std;
long long a[10000009],b[10000009];
char c[10000009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string .out","w",stdout);
    int n,ans;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i]; 
	}
for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b[j]+=c[i]; 
       }
    }
	for(int i=1;i<=n;i++){
		if(b[i]==b[n+1-i]){
			cout<<"0";
			return 0;
		}
		else{
            b[n+1-i]=b[i];
            ans++;
		}
	}
cout<<ans;
}
