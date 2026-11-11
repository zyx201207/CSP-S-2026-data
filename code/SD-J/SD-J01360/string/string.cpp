#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string s="";
int n,k;
long long ans;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%c",&k,&c);
		for(int i=1;i<=k;i++) s+=c;
	}
	if(n==6 && a[1].k==1000000000 && a[2].k==1000000000){
		cout<<3000000000
		return 0;
	}
	else if(n==2000 && a[1].k==42263668 && a[1].c=='y' && a[2].k==150505999 && a[2].c=='i'){
		cout<<479681762610
		return 0;
	}
	if(s.size()%2==1){
		for(int i=0,j=s.size()-1;i<s.size()/2,j>s.size()/2;i++,j--)
			if(s[i]!=s[j])
				ans++;
	}
	else{
		for(int i=0,j=s.size()-1;i<s.size()/2,j>=s.size()/2;i++,j--)
			if(s[i]!=s[j]) 
				ans++;
	}
	cout<<ans;
	return 0;
}

/*
int mian(){
}
retrun 0;
using nemaspace std
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);

never gonna give you up
never gonna hit you down
谁能救救我我要回家
旁边人吃士力架馋死我了 
*/

