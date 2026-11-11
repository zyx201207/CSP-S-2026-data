#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],m,cnt,ans;
char b[200010];
string s,s1[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s1[i]=b[i];
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	m=s.size();
	if(m%2==0){
		for(int i=0;i<m/2;i++){
			if(s[i]!=s[m-i]){
				ans++;
			}
		}
	}
	else{
		for(int i=0;i<m/2;i++){
			if(s[i]!=s[m-1-i]){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
