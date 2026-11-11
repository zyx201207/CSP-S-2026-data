#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
struct str{
	int a;
	string c;
}t[200005];
string s="",v="";
int main(){
	freopen("string4.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>t[i].a>>t[i].c;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<t[i].a;j++){
			s+=t[i].c;
		}
	}
	bool flag=false;
	for (int i=s.size()/2+1;i<s.size();i++){
		if (s.size()%2!=0 && s[i]==s[i-((s.size()-1)-(s.size()-1-i)*2)]){
			flag=true;
		}
		else if (s.size()%2!=0 && s[i]!=s[i-(s.size()-1)-(s.size()-1-i)*2]){
			flag=false;
			break;
		}
		else if (s.size()%2==0 && s[i]==s[i-(s.size()-1)-(s.size()-1-i)*2]){
			flag=true;
		}
		else if (s.size()%2==0 && s[i]!=s[i-(s.size()-1)-(s.size()-1-i)*2]){
			flag=false;
			break;
		}
	}
	for (int i=0;i<n;i++){
		if (t[i].c==t[i+1].c){
			flag=true;
		}
		else{
			flag=false;
			break;
		}
	}
	if (flag==true){
		cout<<0;
	}
	else{
		for (int i=s.size()/2+1;i<s.size();i++){
			if (s.size()%2!=0){
				if (s[i]!=s[i-(s.size()-1)-(s.size()-1-i)*2]){
					s[i]=s[i-(s.size()-1)-(s.size()-1-i)*2];
					ans++;
				}
			}
			else{
				if (s[i]!=s[i-(s.size()-1)-(s.size()-1-i)*2]){
					s[i]=s[i-(s.size()-1)-(s.size()-1-i)*2];
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
