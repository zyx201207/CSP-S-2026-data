#include<bits/stdc++.h>
using namespace std;
int n,m,b[500005],a[300005];
string s1="";
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i = 1;i <= n;i++){
    	char c;
    	cin>>c;
    	s1+=c;
    	b[i]=c-'0';
	}
	if (n<=500&&m<=200){
		for (int x = 1;x <= n;x++){
		string s="";
		for (int i = x;i <= n;i++){
			for (int j = 0;j < s.size();j++){
				
				if (s[j]-'0'==b[i]){
					s=s.substr(0,j);
					break;
				}
			}
			s+=b[i]+'0';
		}
		for (int i = 0;i < s.size();i++){
			for (int j = 1;j <= m;j++){
				if (s[i]-'0'==j){
					a[j]++;
					break;
				}
			}
		}	
	}
	for (int i = 1;i <= m;i++) cout<<a[i]<<' ';
	}
	else {
		for (int i = 1;i <= m;i++) cout<<i<<' ';
	}
	return 0;
}
