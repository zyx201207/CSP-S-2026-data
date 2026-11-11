#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],dp[N],cnt;
string c[N],s;
bool check(string s){
	int i=0,j=s.size();
	while(i<=j){
		if(s[i]!=s[j]){
			return 0;
		}
		i++;j--;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	bool f=0;
	long long l=s.size();
	for(int i=0;i<l;i++){
		if(f==1) break;
		for(int j=l;j>0;j--){
			if(check(s)){
				f=1;
				break;
			}	
			if(s[i]!=s[j]){
				s[j]=s[i];
			}
		}
		cnt++;
	}
	cout<<cnt;
	return 0; 
}
