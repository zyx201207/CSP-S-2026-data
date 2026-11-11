#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt=0;
	string s;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		long long m;
		char ww;
		cin >> m >> ww;
		for(int j=0;j<m;j++){
			s+=ww;
		}
		
	}
	
	long long len=s.size()+1;
	if(len%2==0){
		for(int i=1;i<=(len-2)/2;i++){
			if(s[i-1]!=s[len-i-1]){
				cnt++;
			}
		}	
	}else{
		for(int i=1;i<=(len-1)/2;i++){
			if(s[i-1]!=s[len-i-1]){
				cnt++;
			}
		}
		
	}
	cout << cnt << "\n";
	return 0;
}
