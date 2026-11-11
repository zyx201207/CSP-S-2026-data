#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cnt=0;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		string c;
		cin>>a>>c;
		string u=(string)c;
		while(u.length()!=a){
			if(u.length()*2<=a){
				u=u+u;
			}else{
				int id=1;
				while(id*2<=a-u.length()){
					id*=2;
				}
				string f=(string)c;
				for(int i=0;i<id-1;i++){
					f=f+f;
				}
				u=u+f;
			}
		}
		s=s+u;
	}
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}

