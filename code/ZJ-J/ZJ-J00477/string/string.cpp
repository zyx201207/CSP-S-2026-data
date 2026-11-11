#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int cnt=0;
	int n;
	cin>>n;
	int k=0;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s[k]=a;
			k++;
		}
	}
	for(int i=0;i<k/2;i++){
		if(s[i]!=s[k-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
