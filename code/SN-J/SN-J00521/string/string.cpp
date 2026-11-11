#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define endl '/n'
int n,sum=0,ans=LLONG_MAX,kkk;
string s;
void solve(string s){
	string t;
	if(kkk%2==0){
		for(int i=1;i<=s.size()/2;i++){
			t+=s[i];
		}
		string t2=" "+t;
		reverse(t.begin(),t.end());
		t2+=t;
//		cout<<s<<"`"<<t2<<endl;
		for(int i=1;i<=s.size();i++){
			if(s[i]!=t2[i]){
				sum++;
			}
		}
	}else{
		for(int i=1;i<s.size()/2;i++){
			t+=s[i];
		}
		string t2=" "+t+s[kkk/2+1];
		reverse(t.begin(),t.end());
		t2+=t;
//		cout<<s<<"`"<<t2<<endl;
		for(int i=1;i<=s.size();i++){
			if(s[i]!=t2[i]){
				sum++;
			}
		}
	}
	ans=min(ans,sum);
}
/*
我是退化了吗，怎么T2都想不出正解
期望85分 
*/
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		int x;
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
		kkk+=x;
	}
	solve(" "+s);
	reverse(s.begin(),s.end());
	solve(" "+s);
	cout<<ans;
	return 0;
}
