#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0;
struct node{
	long long a;
	char c;	
}str[200005];
string s;
int tmpi=0;
int main(){
	int i=1;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int k=1;
	for(i=1;i<=n;i++){
		cin>>str[i].a>>str[i].c;
		
		for(int j=1;j<=str[i].a;j++){
			
			s[k]=str[i].c;
			k++;
		}
	}
	k--;
	if(k%2!=0){
		for(int i=1;i<k/2+1;i++){
			if(s[i]!=s[k-i+1]) cnt++;
		}
	}
	else{
		for(int i=1;i<=k/2;i++){
			if(s[i]!=s[k-i+1]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}