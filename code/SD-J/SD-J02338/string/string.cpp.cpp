#include<bits/stdc++.h>
using namespace std;
int n,ans=0,j=1,l[200005],d=1;
string s,t[200005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		cin>>t[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		if(l[i]>maxn) maxn=l[i];
	}
	while(j<=n){
		if(d>l[j]){
			j++;d=1;
		}
		s+=t[j];
		d++;
	}
	int x=0;
	for(int k=((s.size()-1));x<=((s.size()-1)/2)&&k>=(s.size()-1)/2;k--){
	if(s[x]!=s[k]){
		ans++;
	}
		x++;
	}
	cout<<ans;
	return 0; 
}
