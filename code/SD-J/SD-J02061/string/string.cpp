#include<bits/stdc++.h>
using namespace std;
char s[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char c;
	int pos=0,x;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=pos+1;j<=pos+x+1;j++){
			s[j]=c;
		}
		pos+=x;
	}
	int cnt=0;
	for(int i=1,j=pos;i<=(int)pos/2&&j>=(pos-(int)pos/2)&&i!=j;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
