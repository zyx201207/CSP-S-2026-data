#include<bits/stdc++.h>
using namespace std;
int n,m,k=0,a[200005];
string s[200005]={""},s1="";
bool cmp(int a,int b){
	return a>b;
}
void to_binary(int n){
	while(n!=0){
		int a=n/2,b=n%2;
		s[k].push_back(char(b+'0'));
		n/=2;
	}
}
int to_int(string s){
	int k1=0;
	for(int i=0;i<s.size();i++){
		k1=k1*2+int(s[i]-'0');
	}return k1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}stable_sort(a,a+n,cmp);
	for(int i=0;i<m;i++){
		to_binary(a[i]);
		cout<<s[k]<<endl;
		if(k==0)s1=s[k];
		else{
			for(int j=0;j<min(s1.size(),s[k].size());j++){
				if(s[k][j]==s1[j]&&s[k][j]=='1')s1[j]='1';
				else s1[j]='0';
			}for(int j=min(s1.size(),s[k].size());j<s1.size();j++)s1[j]='0';
		} 
		k++;
	}reverse(s1.begin(),s1.end());
	cout<<to_int(s1);
	return 0;
}
