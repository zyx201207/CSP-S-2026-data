#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
ll num;char ch;//字符串的部分 
ll n,sum,ans;string s1,s2;//sum：字符串总长 ans:答案 
vector<pair<int,char> > p[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>p[i].int>>p[i].second;
	} 
	
	for(ll i=0;i<s1.size();i++){
		s2[i]=s1[s1.size()-i-1];
		//cout<<s2[i];
		if(s1[i]!=s2[i])ans++;
	}
	/*for(int i=0;i<=s1.size();i++){
		cout<<s1[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<=s1.size();i++){
		cout<<s2[i]<<" ";
	}
	cout<<endl;*/
	
	cout<<ceil(ans*1.0/2);
	return 0;
}
