#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,cnt[300005];
char a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s="";
		for(int j=i;j<=n;j++){
			s+=a[j];
			for(int k=s.size()-1;k>=0;k--){
				if(a[j]==s[k]&&s.size()-1!=k){
					s.erase(k,s.size()-1-k);
				}
			}
		}
		for(int j=0;j<s.size();j++){
			cnt[s[j]-'0']++;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' '; 
	return 0;
}
