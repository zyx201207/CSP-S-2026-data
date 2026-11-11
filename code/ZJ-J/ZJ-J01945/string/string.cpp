#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long len;
string s;
bool ish(string s){
	string s1=s;
	reverse(s.begin(),s.end());
	if(s==s1) return 1;
	else return 0;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("strint.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	while(n--){
		long long num;
		char a;
		cin>>num>>a;
		len+=num;
		while(num--){
			s+=a;
		}
	}
	if(ish(s)){
		cout<<"0";
		return 0;
	}else{
		if(len%2==1){
			string zj=s.substr(0,len/2);
			reverse(zj.begin(),zj.end());
			string jd=s.substr(0,len/2+1)+zj;
			for(int i=0;i<len;i++){
				if(s[i]!=jd[i]){
					ans++;
				}
			}
		}else{
			string zj1=s.substr(0,len/2);
			reverse(zj1.begin(),zj1.end());
			string jd1=s.substr(0,len/2)+zj1;
			for(int i=0;i<len;i++){
				if(s[i]!=jd1[i]){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
