#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],t,y,x,maxx;
long long ans,ans1;
string s,c[N];
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		maxx=max(maxx,a[i]);
		if(i!=1&&(c[i]!=c[i-1]))f=1;
	}
	if(!f){
		cout<<0;
		return 0;
	}
	if(maxx<=500){
		for(int i=1;i<=n;i++){
			while(a[i]--){
				s+=c[i];
			}
		}
		int len=s.size();
		for(int i=0;i<len/2;i++){
			if(s[i]!=s[len-i-1]){
			ans++;
			}
		}
		cout<<ans;	
	}
	else{
		for(int i=1;i<=n/2;i++){
			if(c[i]!=c[n+1-i])ans1+=a[i];
		}
		cout<<ans1;
	}
	return 0;
}
