#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
long long a[N];
int n,ans=0,anns=0;
string s,str,stri;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		string c;
		cin>>c;
		for(int j=1;j<=a[i];j++){
			str[i]+=c[i];
			ans++;
		}
	}
	for(int i=ans;i>=1;i--){
		stri[i]+=str[i];
	}
	for(int i=1;i<=ans;i++){
		for(int j=ans;j>=1;j--){
			if(str[i]==stri[i]){
				continue;
			}
			else{
				anns++;
			}
		}
	}
	cout<<anns;
	return 0;
} 
