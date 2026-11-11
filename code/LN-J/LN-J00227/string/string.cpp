#include<bits/stdc++.h>
using namespace std;  

string s;
bool flag=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,cnt=0;
	cin>>n;
	char cc='^';
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a;
		cin>>c;
		if(cc!=c&&cc!='^'){
			flag=1;
			}
		cc=c;
		
		for(int j=1;j<=a;j++){
			s[cnt++]=c;
			
	
	}
	}
	if(!flag){
		cout<<0;
		return 0;
		}
	long long ans=0;
	for(long long i=0;i<=cnt/2;i++){
		if(s[i]!=s[cnt-i-1]){
			ans++;
			}
		}


	cout<<ans;




	return 0;
}
