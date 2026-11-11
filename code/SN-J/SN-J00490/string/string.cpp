#include<bits/stdc++.h>
using namespace std;
string s;
long long a,b,cnt=0;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b>>c;
		for(int j=0;j<b;j++){
			s+=c;
		}
	}
	int d=s.size();
	if(d%2==0){
		for(int i=0;i<=d/2-1;i++){
			if(s[i]!=s[d-1-i]){
				cnt++;
			}
		}
		cout<<cnt;
	}else if(d==1||d==0){
		cout<<0;
	}else{
		for(int i=0;i<=(d-3)/2;i++){
			if(s[i]!=s[d-1-i]){
				cnt++;
			}
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
