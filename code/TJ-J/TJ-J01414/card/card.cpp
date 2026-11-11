#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
char a[100005];
ll b[100005];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    for(int i=0;i<n;i++){
    	s="";
    	for(int j=1+i;j<=n;j++){
    		s+=a[j];
		}
		for(int j=0;j<s.size();j++){
			char u=s[j];
			for(int k=0;k<=j;k++){
				if(u==s[k]){
					for(int l=k;l<j;l++){
						s[l]=' ';
					}
				}
			}
		}
		for(int i=0;i<s.size();i++){
			if(s[i]!=' ') b[s[i]-'0']++;
		}
	}
    for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
