#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n;string s1;int k;char c;int a[10086];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>c;a[i]=k;
		for(int j=1;j<=k;j++)s1+=c;
	}
	string s2=s1;
	reverse(s1.begin(),s1.end());
	if(s1==s2)cout<<0;
	else cout<<a[1];
	return 0;
}//lhd
//wo you dian wan le
//QAQ
/*
lhd wb wf gooooooooooooooooooood!
*/ 
