#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt,ans;
string s,c;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
			cnt++;
		}
	}
	if(cnt==1){
		cout<<0;
	}else{
		if(cnt%2!=0){
		for(int i=1;i<=cnt/2;i++){
			if(s[cnt/2-i]!=s[cnt/2+i]){
				ans++;
			}
		}
		}else{
			for(int i=0;i<cnt/2;i++){
				if(s[cnt/2+i]!=s[cnt/2-1-i]){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	
	
	
	return 0;
}
