#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
struct node{
	int num;
	char ch;
}a[N];
bool check(string st){
	int le=st.size();
	for(int i=0;i<le/2;i++){
		if(st[i]!=st[le-i-1]) return 0;
	}
	return 1;
}
string s="";
char che;
map<char,int> mp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int ma=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
		for(int j=1;j<=a[i].num;j++){
			s+=a[i].ch;
		}
		mp[a[i].ch]+=a[i].num;
	}
	if(check(s)){
		 cout<<0;
		 return 0;
	}
	long long l=s.size();
	long long cnt=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			if(mp[s[i]]>=mp[s[l-i-1]]){
				che=s[i];
			}else che=s[l-i-1];
			if(s[i]!=che) cnt++;
			if(s[l-i-1]!=che) cnt++;	
		}	
	}
	cout<<cnt;
	return 0;
} 
