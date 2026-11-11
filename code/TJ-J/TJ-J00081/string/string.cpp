#include<bits/stdc++.h>
using namespace std;
long long n,x[1000000000000000010],ans=0;
string s,y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n==1){
		cout << 0;
	}else{
		for(int i=1;i<=n;i++){
			cin >> x[i] >> y;
			while(x[i]--){
				s+=y;
			}
		}
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1]){
				ans++;
			}
		}
		cout << ans;
	}
	return 0;
} 
