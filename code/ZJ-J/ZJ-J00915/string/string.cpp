#include<bits/stdc++.h>
using namespace std;
unsigned long long n,cnt;
unsigned long long mx,num;
string s1,s2;
struct str{
	unsigned long long x;
	string a;
}s[200005];
struct str1{
	unsigned long long x;
	string a;
}l[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].a;
		mx=max(mx,s[i].x);
		num+=s[i].x;
	}
	for(int i=1;i<=n;i++){
		l[i].x=s[n-i+1].x;
		l[i].a=s[n-i+1].a;
	}
	if(mx*n<1LL*100000000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=s[i].x;j++) s1+=s[i].a;
			for(int j=1;j<=l[i].x;j++) s2+=l[i].a;
		}
		for(int i=0;i<num;i++)
			if(s1[i]!=s2[i])
				cnt++;
		cout<<cnt/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(l[i].x==s[i].x){
			if(l[i].a!=s[i].a) cnt+=l[i].x;
		}else if(l[i].x>s[i].x){
			int k=i;
			while(l[k].x>s[k].x){
				if(s[k+1].x<(l[k].x-s[k].x)){
					if(s[k+1].a!=l[k].a) cnt+=s[k+1].x;
					s[k+1].x=0;
				}else{
					if(s[k+1].a!=l[k].a) cnt+=(l[i].x-s[i].x);
					s[k+1].x-=(l[i].x-s[i].x);
				}
				++k;
			}
		}else{
			int k=i;
			while(l[k].x<s[k].x){
				if(l[k+1].x<(s[k].x-l[k].x)){
					if(l[k+1].a!=s[k].a) cnt+=l[k+1].x;
					l[k+1].x=0;
				}else{
					if(l[k+1].a!=s[k].a) cnt+=(s[k].x-l[k].x);
					l[k+1].x-=(s[k].x-l[k].x);
				}
				++k;
			}
		}
	}
	cout<<cnt/2;
	return 0;
}