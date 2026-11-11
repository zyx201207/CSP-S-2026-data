#include<bits/stdc++.h>
using namespace std;
int a[500005]={0};
int ans[300005]={0};
string s="";
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s="";
		int check[300005]={0};
		for(int j=i;j<=n;j++){
			s+=a[j]+'0';
			check[a[j]]++;
			if(check[a[j]]==2){
				for(int k=0;k<s.length();k++){
					if(a[j]==s[k]-'0'){
						for(int l=k+1;l<s.length();l++){
							check[s[l]-'0']--;
						}
						s=s.substr(0,k+1);
						break;
					}
				}
				check[a[j]]--;
			}
		}
		for(int j=0;j<s.length();j++){
			ans[s[j]-'0']++;
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0; 
}
