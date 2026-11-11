#include<bits/stdc++.h>
using namespace std;
int a;
int ans;
string cc;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			cc.push_back(c);
		}
	}
	if(cc.size()%2!=0){
		int flag=cc.size()/2;
		for(int i=1;i<=flag;i++){
			if(cc[flag+i]!=cc[flag-i]){
				ans++;
			}
		}
	}else{
		int flag=cc.size()/2;
		int flagg=flag-1;
		if(cc[flag]!=cc[flagg]){
			ans++;
		}
		for(int i=1;i<=flag;i++){
			if(cc[flagg+i]!=cc[flag-i]){
				ans++;
			}
		}
	}
	
	cout<<ans;
	

	return 0;
	
}
