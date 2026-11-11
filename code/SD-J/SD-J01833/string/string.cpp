#include<bits/stdc++.h>
using namespace std;
int n,w=1,j,sum;
char s[1000000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(j=w;j<(a+w);j++) s[j]=c;
		w=j;
	}
	int l=1,r=j-1;
	while(l<r){
		if(s[l]!=s[r])sum++;
		l++,r--;
	}
	cout<<sum;
	return 0;
}
