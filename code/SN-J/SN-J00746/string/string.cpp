//SN-J00746 张宸熙 西安市第十二中学 
#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int n;
char b[N],c[N];
int a[N];
int f;
long long s,cnt,cnt1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			c[++cnt]=b[i];
		}
		s+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=b[i+1]){
			f=1;
			break;
		}
	}
	if(f==0){
		cout<<0;
		return 0;
	}
	int t=s/2;
	for(int i=1;i<=t;i++){
		if(c[i]!=c[s-i+1]){
			cnt1++;
		}
	}
	cout<<cnt1;	
}
