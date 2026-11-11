#include<bits/stdc++.h>
using namespace std;
long long a[100005];
string k(int n){
	string s;
	while(n>0){
		s=char(n%2)+s;
		n/=2;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	string s=" ";
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;i++){
			if(s==" "){
				s=k(a[j]);
			}
			else{
				string str=k(a[j]);
				long long lena=s.size();
				long long lenb=str.size();
				long long len=min(lena,lenb);
				string skr="";
				for(int i=0;i<len;i++){
					if(s[i]=='1'&& str[i]=='1'){
						skr='1'+skr;
					}
					else{
						skr='0'+skr;
					}
				}
				if(skr>s){
					s=skr;
				}
			}	
		}
	}
	cout<<s;
}
