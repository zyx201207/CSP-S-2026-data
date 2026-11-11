#include<bits/stdc++.h>
using namespace std;
int a[500005];
int bottle[10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	string s="";
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s="";
		for(int j=i;j<=n;j++){
			char x=a[j]+'0';
			int pos=-1;
			for(int w=0;w<s.size();w++){
				if(s[w]==x){
					pos=w;
					break;
				}
			}
			if(pos==-1){
				s+=x;
				continue;
			}
			else{
				for(int w=s.size()-1;w>=pos;w--){
					s[w]='0';
				}
				s+=x;
			}
		}
		for(int j=0;j<s.size();j++){
			if(s[j]=='0'){
				continue;
			}
			int u=s[j]-'0';
			bottle[u]++;
		}
	}
	for(int i=1;i<=m;i++){			
			cout<<bottle[i]<<" ";
	}
	return 0;
}
