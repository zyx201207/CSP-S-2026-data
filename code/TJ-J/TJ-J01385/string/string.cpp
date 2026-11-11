#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c,d,lenth,ans,ls,no=1;
string ss;
struct vet{
	long long a;
	char c;
}s[100005];
vet t[100005];
char cc;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
		lenth+=s[i].a;
	}
	ls=s[0].a;
	if(lenth%2!=0){
		for(int i=1;i<=lenth/2;){
			t[i-1].c=s[i-1].c;
			t[i-1].a=ls;
			if(i+t[i-1].a>=lenth/2){
				i+=max(no,lenth/2-i);
				ls=lenth/2-i+1;
			}
			else{
				i+=t[i-1].a;
				ls=s[i-1].a;
			}
		}
		for(int i=0;i<lenth;i++){
			cout<<t[i].a<<' '<<t[i].c<<endl;
		}
		for(int i=lenth/2+1;i<lenth;i++){
			if(t[i-lenth/2-1].c==s[i].c){
				if(t[i-lenth/2-1].a=s[i].a){
					i+=t[i-lenth/2-1].a;
					continue;
				}
				else{
					ans+=t[i-lenth/2-1].a-s[i].a;
					i+=t[i-lenth/2-1].a-s[i].a;
					continue;
				}
			}
			ans+=t[i-lenth/2-1].a;
			i+=t[i-lenth/2-1].a;
		}
	}
	else{
		for(int i=1;i<=lenth/2;){
			t[i-1].c=s[i-1].c;
			t[i-1].a=ls;
			if(i+t[i-1].a>=lenth/2){
				i+=max(no,lenth/2-i);
				ls=lenth/2-i+1;
			}
			else{
				i+=t[i-1].a;
				ls=s[i-1].a;
			}
		}
		for(int i=0;i<lenth;i++){
			cout<<t[i].a<<' '<<t[i].c<<endl;
		}
		for(int i=lenth/2;i<lenth;i++){
			if(t[i-lenth/2].c==s[i].c){
				if(t[i-lenth/2].a=s[i].a){
					i+=t[i-lenth/2].a;
					continue;
				}
				else{
					ans+=t[i-lenth/2].a-s[i].a;
					i+=t[i-lenth/2].a-s[i].a;
					continue;
				}
			}
			ans+=t[i-lenth/2].a;
			i+=t[i-lenth/2].a;
		}
	}
	cout<<ans;
	return 0;
}
