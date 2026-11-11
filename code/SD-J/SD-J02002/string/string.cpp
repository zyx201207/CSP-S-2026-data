#include<bits/stdc++.h>
using namespace std;
char s[200005];
int k=0,cnt=0,ans=0;
int a;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
int n;
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a>>c;
	while(a!=0){
	    k++;
	    ans++;
		s[k]=c;
		a--;
	}
}
for(int i=1;i<=ans;i++){
	if(s[i]!=s[ans-i+1]){
		s[i]=s[ans-i+1];
		cnt++;
	}
}
cout<<cnt;
	return 0;
}
