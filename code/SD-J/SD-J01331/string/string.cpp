#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char c;
	long long tit=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[j+tit]=c;
//			cout<<s[j+tit];
		}
		tit+=a;
	}
//	cout<<tit;
	long long mid=(tit+1)/2;
	for(int i=1;i<=mid;i++)
//		cout<<s[i]<<' ';
		if(s[i]==s[tit-i+1])
			ans=ans;
		else
			ans++;
//		cout<<s[i]<<' '<<s[tit-i+1];
	cout<<ans;
	return 0;
}
/*
2
2 a
3 a
0

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 a
2 b
1 c
*/
