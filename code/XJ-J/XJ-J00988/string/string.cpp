#include<bits/stdc++.h>
using namespace std;
const int N = 1e9+1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int ans=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	
	int lens = s.size();
	for(int i=0;i<=lens;i++){
		if(s[i+1]==s[lens-i]){
			printf("0");
		}
		else{
			break;
		}
	}
	
	
	cout<<ans;
	return 0;
}
