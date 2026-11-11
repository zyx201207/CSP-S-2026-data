#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long f,cnt=0;
	char s1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>f>>s1;
		for(int j=1;j<=f;j++){
			s[cnt+j]=s1;
		}
		cnt+=f;
	}
	if(cnt%2==0){
		for(int i=1;i<=cnt/2;i++){
			if(s[i]==s[cnt-i+1]) continue;
			else ans++;
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=cnt/2+1;i++){
			if(i==cnt/2+1) continue;
			if(s[i]==s[cnt-i+1]) continue;
			else ans++;
		}
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
