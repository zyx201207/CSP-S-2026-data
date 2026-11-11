#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long ans=0;
	string s;
	for(int i=0;i<n;i++){
		int num = 0;
		char word;
		cin >> num >> word;
		for(int j=0;j<num;j++) s+=word;
	}
	//cout << s << endl;
	
	string s2;
	for(int i=s.size()-1;i>=0;i--){
		s2 += s[i];
	}
	//cout << s2;
	if(s==s2){
		cout << 0;
		return 0;
	}
	
	int len = s.size();
	string s3;
	for(int i=0;i<len/2;i++){
		if(s[i] != s3[i]){
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
