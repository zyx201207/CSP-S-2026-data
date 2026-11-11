#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N];
string s;
int tot[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	bool flagxx=0;
	for(int i=1;i<=n;++i)if(a[i]<a[i-1])flagxx=1;
	if(flagxx==0){
		for(int i=1;i<=n;++i){
			if(a[i]==a[i+1])continue;
			tot[a[i]]=i;
		}
		int mx=INT_MIN;
		for(int i=1;i<=n;++i)mx=max(mx,a[i]);
		for(int i=1;i<=mx;++i)cout<<tot[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;++i){
		s="";
		for(int j=i;j<=n;++j){
			if(j==i){
				s+=char(a[j]+'0');
				continue;
			}
			else{
				int k=s.find(char(a[j]+'0'));
				if(k>=0 && k<=s.size()-1){
					s.erase(k,s.size());
					s+=char(a[j]+'0');
				}
				else{
					s+=char(a[j]+'0');
				}
			}
		}
		for(int i=0;i<s.size();++i)tot[int(s[i]-'0')]++;
	}
	int mx=INT_MIN;
	for(int i=1;i<=n;++i)mx=max(mx,a[i]);
	for(int i=1;i<=mx;++i)cout<<tot[i]<<' ';
	return 0;
}
