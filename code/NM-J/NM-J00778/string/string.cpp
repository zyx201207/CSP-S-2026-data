#include<bits/stdc++.h>
using namespace std;
char s[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=0,u,ans=0;
	char a;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> u >> a;
		for(int j=1;j<=u;j++){
			s[num]=a;
			num++;
		}
	}
	int c=num-1;
	bool q=true;
	for(int i=1;i<=c;i++){
		if(s[0]!=s[i]){
			q=false;
			break;
		}
	}
	if(q==true){
		cout << "0";
		return 0;
	}
	for(int i=0;i<=c/2;i++){
		if(s[i]!=s[num]){
			ans++;
		}
		num--;
	}
	cout << ans;
	return 0;
}
