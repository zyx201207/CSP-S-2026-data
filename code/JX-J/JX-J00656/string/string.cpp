#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000000],xx,b[1000000];
string s[1000000],aa,ss[1000000];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int id=0;
	for(int i=1;i<=n;i++){
		int x;
		string c;
		cin>>x>>c;
		if(i==1){
			a[++id]=x,s[id]=c;
			aa=c;
			continue;
		}
		if(aa==c){
			a[id]+=x;
		}
		else{
			a[++id]=x,s[id]=c;
		}
		aa=c;
	}
	n=id;
	for(int i=1;i<=n;i++){
		b[i]=a[n-i+1],ss[i]=s[n-i+1];
	}
	int hs=b[1],ix=1,ans=0;
	string cc=ss[1];
	for(int i=1;i<=n;i++){
		while(a[i]){
			if(a[i]<=hs){
				if(s[i]!=cc){
					ans+=a[i];
				}
				hs-=a[i];
				a[i]=0;
				break;
			}
			else{
				if(s[i]!=cc){
					ans+=hs;
				}
				a[i]-=hs;
				hs=b[++ix],cc=ss[ix];
			}
		}
	}
	cout<<ans/2;
	return 0;
}
//aabbc
//cbbaa
//2a 2b 1c
//1c 2b 2a
