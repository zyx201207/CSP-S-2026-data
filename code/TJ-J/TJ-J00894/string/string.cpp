#include<bits/stdc++.h>
#define int long long
using namespace std;
struct longstr{
	int a;
	string c;
};
int n;
longstr s[200009];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&s[i].a);
		cin>>s[i].c;
	}
	if(n==1) cout<<0;
	else if(n==2){
		if(s[0].c==s[1].c) cout<<0;
		else cout<<min(s[0].a,s[1].a);
	}
	else if(2<n&&n<=10){
		string x="";
		for(int i=0;i<n;i++){
			for(int j=0;j<s[i].a;j++){
				x+=s[i].c;
			}
		}
		string x1=x;
		reverse(x1.begin(),x1.end());
		int num=0;
		for(int i=0;i<x.size();i++){
			if(x[i]!=x1[i]){
				num++;
			}
		}
		cout<<num/2;
	}
	else{
		string x="";
		for(int i=0;i<n;i++){
			for(int j=0;j<s[i].a;j++){
				x+=s[i].c;
			}
		}
		string x1=x;
		reverse(x1.begin(),x1.end());
		int num=0;
		for(int i=0;i<x.size();i++){
			if(x[i]!=x1[i]){
				num++;
			}
		}
		cout<<num/2;
	}
	return 0;
}
//I like "//freopen"!!!
//I hope that I can get the score of #1~#12 and #17,#18
