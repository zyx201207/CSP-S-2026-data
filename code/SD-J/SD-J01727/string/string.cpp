#include <bits/stdc++.h>
using namespace std;
const int num=2e5+5;
int a[num];
char c[num];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cnt=0;
	cin>>n;    
	string s[5];    
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s[1]+=c[i];
		}
	}
	s[2]=s[1];
	reverse(s[2].begin(),s[2].end());
	if(s[2]==s[1]){
		cout<<0;
		return 0;
	}else{
		int l=s[1].size();
		if(l%2==0){
			l/=2;
		}else{
			l=l/2+1;
		}
		for(int i=1;i<=l;i++){
			if(s[1][i]!=s[2][i]){
				cnt+=1;
			}
		}
	}
	cout<<cnt;
	if(n<2000)return 0;
	else cout<<0; 
}
