#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
char c[N];
int n,ans,maxx=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	char x;
	cin>>x;
	c[i]=x;
	maxx=max(maxx,a[i]);
	if(n*maxx<1e8){
		string s=" ";
		int len=s.size();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				if(s[i]==s[len-i+1]){
					continue;
				} 
				ans++;
			}
			cout<<ans;
		}else{
			int ans=0;
			for(int j=1;j=n;i<=j){
				if(c[i]==c[j]){
					
				}
				else{
					if(a[i]>a[j]){
						i++;
						a[i]-=a[j];
					}
					else if(a[i]<a[j]){
						i++;
						a[j]-=a[i];
					} 
				}
			}
		}
	}
	cout<<maxx;
	return 0;
}

