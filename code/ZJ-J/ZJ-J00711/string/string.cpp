#include<bits/stdc++.h>
using namespace std;const int N=200005;
int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*w;
}
int n;
int a[N];
int l=0;
char word[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>a[i]>>word[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=word[i];
		}
	}
	//cout<<s<<" "<<l<<'\n';
	int ans=0;
	if(l%2==1){
		for(int i=l/2,j=l/2+2;i>=1,j<=l;i++,j++){
			if(s[i-1]!=s[j-1]){
				ans++;
			}
		}
	}else{
		for(int i=l/2,j=l/2+1;i>=1,j<=l;i++,j++){
			if(s[i-1]!=s[j-1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
