#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[200005],top,ans;
char chh,ch[200005],c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>chh;
		ch[i]=chh;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[++top]=ch[i];
		}
	}
	for(int i=1;i<=(top/2+(top%2));i++){
		if(c[i]!=c[top+1-i]) ans++; 
	}
	cout<<ans<<'\n'; 
	return 0;
}
/*
fc string1.ans string1.out /n
fc string2.ans string2.out /n
fc string3.ans string3.out /n
fc string4.ans string4.out /n
fc string5.ans string5.out /n
finished.
*/
