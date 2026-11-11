#include<bits/stdc++.h>
using namespace std;
unsigned long long s[500010],ans;
long long a,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+a);
	ans=s[a];
	for(int i=a-1;i>=a-b+1;i--){
		ans=ans&s[i];
	}
	cout<<ans;
	return 0;
}
