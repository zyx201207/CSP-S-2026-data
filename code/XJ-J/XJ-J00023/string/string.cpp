#include<bits/stdc++.h>
using namespace std;
string s1,s2;
char c;
long long n,a,j=0,w;
void hw(){
	for(int i=s1.size()-1;i>=0;i--){
		s2=s2+s1[i];
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]) w++;
	}
	return ;
}
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s1+=c;
		}
	}
	hw();
	cout<<w/2;
	return 0;
} 
