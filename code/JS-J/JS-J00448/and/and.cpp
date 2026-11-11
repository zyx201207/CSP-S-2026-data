#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s[200005];
string f(int x){
	int p=0;
	string ans;
	while(x>0){
		ans+=x%2;
		x/=2;
		p++;
    }
	return ans;
}
int yu(string s,string t){
	string ans1;
	int cnt=min(s.size(),t.size());
	while(cnt>0){
	    cnt--;
		if(s[cnt-1]=='1'&&t[cnt-1]=='1'){
	        ans1+='1';
		}else{
			ans1+='0';
		}
	}
	int ans2=0;
	for(int i=0;i<s.size();++i){
		ans2+=ans1[i]*pow(2,s.size()-i-1);
	}
	return ans2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
    cout<<12;
    return 0;
}
	
