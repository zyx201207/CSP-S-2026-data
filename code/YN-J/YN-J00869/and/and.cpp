#include<bits/stdc++.h>
using namespace std;
string n,a[i];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++){
		if(a[i]==a[n]&&a[i+1]<=a[i]){
		}else{
			cout<<a[i-1]<<endl;
		}
	}
		return 0;
}   

