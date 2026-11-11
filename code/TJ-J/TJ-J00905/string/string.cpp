#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	unsigned long long n,x,cnt = 0,ans = 0;
	string s,s1;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>x>>s1;
		cnt+=x;
		for(int j = 1;j<=x;j++){
			s+=s1; 
		}
	}
	if(cnt%2==0){
		int l = cnt/2-1;
		int r = cnt/2;
		while(l>=0&&r<cnt){
			if(s[l]!=s[r]){
				ans++;
			}
			l--;
			r++;
		}
	}else{
		int l = cnt/2;
		int r = cnt/2;
		while(l>=0&&r<cnt){
			if(s[l]!=s[r]){
				ans++;
			}
			l--;
			r++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
