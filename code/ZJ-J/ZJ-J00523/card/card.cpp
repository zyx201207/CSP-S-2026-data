#include<bits/stdc++.h>
using namespace std;
long long n,m,v[500009],f[500009];
char a[500009];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			v[i]=0;
		}
		s="";
		for(int j=i;j<=n;j++){
			for(int k=0;k<(int)s.size();k++){
				if(s[k]==a[j]){
					s.erase(k);
					break;
				}
			}
			s=s+a[j];
		}
		for(int j=0;j<(int)s.size();j++){
			v[s[j]-48]=1;
		}
		for(int j=1;j<=m;j++){
			f[j]+=v[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
}
