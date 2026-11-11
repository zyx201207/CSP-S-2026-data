#include<bits/stdc++.h>
using namespace std;
int n,l,ans;
char s[2000000005];
void sadd(int x,char c){
	for(int i=l+1;i<=l+x;i++){
		s[i]=c;
	}
	l+=x;
}
bool is_string(){
	bool flag=true;
	for(int i=1;i<=l/2;i++){
		int r=l+1-i;
		if(s[i]!=s[r]){
			ans++;
			flag=false;
		}
	}
	return flag;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		sadd(x,c);
	}
	
	if(!is_string()){
		cout<<ans;
		return 0;
	}
	else{
		cout<<0;
	}
	return 0;
}

