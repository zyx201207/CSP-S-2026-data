#include<bits/stdc++.h>
using namespace std;
long long int n,ans=0,l,cnt=0;
long long int a[200005];
char c[200005];
string s;
bool b=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	if(n>2000) b=1; 
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(a[i]<=50 and b==0){
			cnt+=a[i];
			for(int j=1;j<=a[i];j++) s+=c[i];
		}
		else b=1;
	}
	if(b==0){
		for(int i=0;i<=cnt/2;i++){
			if(s[i]!=s[cnt-i-1]) ans+=1;
		}
		cout<<ans;
		return 0;
	}
	else{
		long long int j=n; 
		for(int i=1;i<=(n+1)/2 && i<j;i++){
			bool f=0;
			long long int x=a[i];
			while(j>i){
				if(a[j]<x){
					if(c[j]!=c[i]) ans+=a[j];
					x-=a[j];
					j-=1;
				}
				else if(a[j]==x){
					if(c[j]!=c[i]) ans+=x;
					j-=1;
					f=1;
					x=0;
					break;
				}
				else{
					if(c[j]!=c[i]) ans+=x;
					f=1;
					a[j]-=x;
					x=0;
					break;
				}
			}
			if(f==0) break;
		}
	}
	cout<<ans;
	
	return 0;
}
