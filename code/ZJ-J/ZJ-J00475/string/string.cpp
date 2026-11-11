#include<bits/stdc++.h>
using namespace std;
int f[3050][3050],n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cin>>n;
	for(int i=1;i<=n;i++){
		int a;char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c;
	}for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++)
			f[i][j]=1e9;
		f[i][i]=0;
	}for(int i=s.size()/2-1;i>=0;i--){
		for(int j=s.size()/2;j<s.size();j++){
			if(i==j) f[i][j]=0;
			if(s[i]==s[j]) f[i][j]=min(f[i+1][j-1],min(f[i+1][j],f[i][j-1]));
			else f[i][j]=min(min(f[i+1][j-1],f[i+1][j]),f[i][j-1])+1;
		}
	}cout<<f[0][s.size()-1];
	//for(int i=s.size()/2-1;i>=0;i--){
	//	for(int j=s.size()/2;j<s.size();j++){
	//		printf("%d ",f[i][j]);
	//	}puts("");
	//}
}
