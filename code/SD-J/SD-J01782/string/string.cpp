#include <bits/stdc++.h>
using namespace std;
int n,f;
int a;
char c;
long long ans;
string s="*";
int main() {
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	   scanf("%d %c",&a,&c);
	   f+=a;
	   for(int i=0;i<a;i++)
	      s+=c;
	}
	//cout<<s<<f<<endl;
	//cout<<s[1]<<s[f-1];
	bool bl=0;
	if(f%2==1){
	 f+=1;bl=1;}
	int ff=f/2;
	if(bl==0) f++;
	for(int i=1;i<=ff;i++){
		if(s[i]!=s[f-i]) ans++;
	}
	cout<<ans;
	return 0;
}

