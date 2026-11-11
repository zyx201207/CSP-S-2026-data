#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;
ll n,a[maxn],m,cnt;
char c[maxn];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+=' ';
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];	
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}	
	} 
	if(m%2==0){
		for(int i=1;i<=m/2;i++){
			if(s[i]!=s[m-i+1]){
				cnt++;
			}
		}		
	}else{
		for(int i=1;i<=m/2+1;i++){
			if(s[i]!=s[m-i+1]){
				cnt++;
			}
		}		
	}
	cout<<cnt;
	return 0;
}

