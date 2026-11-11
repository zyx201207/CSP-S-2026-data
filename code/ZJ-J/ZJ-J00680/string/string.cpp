#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,a[200005];
long long l,re,cnt;
char s[200005];
char get_char(int x){
	for(int i=1;i<=n;i++){
		if(x>=a[i]) {
			x-=a[i];	
		}
		else{
			return s[i];
		}
	}
	return 'z';
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		l+=a[i];
	}
	if(l%2==0) re=l/2;
	else re=(l+1)/2;
	for(int i=1;i<=re;i++){
		if(get_char(i)!=get_char(n-i+1)) cnt++;
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
