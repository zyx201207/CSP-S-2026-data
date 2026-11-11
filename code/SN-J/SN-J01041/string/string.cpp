#include<bits/stdc++.h>
using namespace std;
char ca[1000010],cb[1000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long point=0;
	long long a;
	string b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
			ca[point]=b[0];
			point++;
	    }
	}
	bool flag=1;
	for(int i=0;i<=s.size()-1;i++){
		if(s[s.size()-1-i]!=s[i])
		{
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	else{
		long long cnt=0;
		for(int i=0;i<=s.size()-1;i++){
			cb[s.size()-1-i]=ca[i];
		}
		long long l=s.size();
		for(int i=0;i<=l/2-1;i++){
			if(ca[i]!=cb[i]){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}
