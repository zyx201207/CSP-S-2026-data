#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,size,ans,sm=1,ts,m=1,l=1,a[N];
string s1[N],s2[N];
char c[N];
vector<char> s;
inline int read(){
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=(ans<<1)+(ans<<3)+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	if(n<=1){
		cout<<"0";
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		a[i]=read(),cin>>c[i];
		if(c[i]==c[i-1]) ts++;
		size+=a[i];
	}
	if(n==2&&(c[1]==c[2])){
		cout<<"0";
		return 0;
	}
	if(ts+1==n){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s.push_back(c[i]);
		}
	}

	long long siz=s.size()/2;
	if(size%2==0){
		for(int i=siz-1;i>=0;i--){
			s1[m++]=s[i];
		}
		for(int i=siz;i<=s.size()-1;i++){
			s2[l++]=s[i];
		}
		
		for(int i=1;i<=siz;i++){
			if(s1[i]!=s2[i]){
				ans++;
			}
		}
	}else{
		for(int i=siz-1;i>=0;i--){
			s1[m++]=s[i];
		}
		for(int i=siz+1;i<=s.size()-1;i++){
			s2[l++]=s[i];
		}
		
		for(int i=1;i<=siz;i++){
			if(s1[i]!=s2[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
