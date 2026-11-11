#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,cnt=0;
char c;
long long turn(string s,long long a){
	string t;
	for(int i=a-1;i>=0;i--){
		t=t+s[i];
	}
	//cout<<s<<endl;
	///cout<<t<<endl;
	for(int i=0;i<=a;i++){
		if(t[i]!=s[i]){
			//cout<<t[i]<<' '<<s[i]<<endl;
			cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		for(int j=1;j<=m;j++){
			s=s+c;
		}
	}
	turn(s,s.size());
	printf("%lld",cnt/2);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
