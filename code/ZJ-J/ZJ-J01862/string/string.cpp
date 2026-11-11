#include<bits/stdc++.h>
using namespace std;
long long ans,n;
long long a[3000000];
char s[3000000];
char anss[3000000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long tab=1;
	for(int i=1;i<=n;i++){
		for(int j=tab;j<tab+a[i];j++){
			anss[j]=s[i];
		}
		tab+=a[i];
	}
	tab--;
	for(int i=1;i<=tab/2;i++){
		if(anss[i]!=anss[tab+1-i]){
			ans++;
		}
	}
	cout<<ans;
}