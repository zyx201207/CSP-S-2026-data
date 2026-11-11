#include<bits/stdc++.h>
using namespace std;
long long a,b,s[500010],dis[500010],ap[500010],p[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>s[i];
		p[s[i]]=a-i+1; 
	}
	for(int i=1;i<=b;i++)cout<<p[b]<<" ";
	return 0;
}
