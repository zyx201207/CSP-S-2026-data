#include<bits/stdc++.h>
#define io ios::sync_with_stdio();cin.tie();cout.tie();
using namespace std;
int a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	io;
	long long ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int i=1,j=n;
	while(i<j&&i!=j+1){
		if(a[i]>a[j]){
			if(s[i]==s[j]){
				a[i]-=a[j];
				a[j]=0;
			}
			else{
				ans+=a[j];
				a[i]-=a[j];
				a[j]=0;
			}
			j--;
		}
		else if(a[i]<a[j]){
			if(s[i]==s[j]){
				a[j]-=a[i];
				a[i]=0;
			}
			else{
				ans+=a[i];
				a[j]-=a[i];
				a[i]=0;
			}
			i++;
		}
		else if(a[i]==a[j]){
			if(s[i]==s[j]){
				a[i]=0;
				a[j]=0;
			}
			else{
				ans+=a[j];
				a[i]=0;
				a[j]=0;
			}
			j--;
			i++;
		}
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!
//02 01A 02 01B
/*
aa bb c
aa ba a

aaaaa cc bbb
aaaaa aa aaa

aa cc dd ff aa
aaccddccaa

ss bb ss aa wwwwww ff rr e w s aa
ssbbssaawwwwwwwaassbbss
9:08 左右一一对应 
9:21 666大样例全过 比第一题简单（bushi 



6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b





*/
