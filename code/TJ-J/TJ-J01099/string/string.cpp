#include<bits/stdc++.h>
using namespace std;
string s,sl,sr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;

	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		char c;
		cin>>c;
		for(int j=0;j<m;j++){
			s+=c;
			cnt++;
		}
	}

	for(int i=0;i<=cnt/2;i++){
		sl+=s[i];
		sr+=s[cnt-i-1];
	}
	for(int i=cnt/2+1;i<=cnt;i++){
		sl+=s[cnt-i-1];
		sr+=s[i];
	}
	int dl=0,dr=0;
	for(int i=0;i<=cnt;i++){
		if(sl[i]!=s[i]){
			dl++;
		}
		if(sr[i]!=s[i]){
			dr++;
		}
	}
	cout<<min(dl,dr);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
