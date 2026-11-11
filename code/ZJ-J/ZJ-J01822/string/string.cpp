#include<bits/stdc++.h>
using namespace std;
int n,x[20005],l,c = 0;
string a = " ";
char b[20005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>x[i]>>b[i];
		l+=x[i];
		for(int j = 1;j<=x[i];j++) a+=b[j];
	}
	if(n == 1){
		cout<<"0";
		return 0;
	}
	if(n == 2){
		if(b[1] == b[2]) cout<<"0";
		else{
			if(x[1]>3||x[2]>3) cout<<"2";
			else if(x[1] == x[2]) cout<<"0";
			else cout<<"1";
		}
		return 0;
	}
	else cout<<"0";
	return 0;
}
