#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans;
struct node{
	int a;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	int i=1,j=n;
	while(i<j){
		if(s[i].a<s[j].a){
			if(s[i].c!=s[j].c)ans+=s[i].a;
			int x=s[j].a-s[i].a;
			i++,s[j].a=x;
		}
		else if(s[i].a==s[j].a){
			if(s[i].c!=s[j].c)ans+=s[i].a;
			i++,j--;
		}
		else{
			if(s[i].c!=s[j].c)ans+=s[j].a;
			int x=s[i].a-s[j].a;
			j--,s[i].a=x;
		}
	}
	cout<<ans;
	return 0;
}
