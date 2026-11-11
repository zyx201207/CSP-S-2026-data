#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n;
	n=read();
	while(n--){
		long long k;
		char c;
		k=read();
		c=getchar();
		for(int i=0; i<k; i++){
			s+=c;
		}
	}
	int i=0,j=s.size()-1,ans=0;
	while(i<j){
		if(s[i]!=s[j])ans++;
		i++,j--;
	}
	cout<<ans;
	return 0;
}
