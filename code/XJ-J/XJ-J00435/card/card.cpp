#include<bits/stdc++.h>
using namespace std;
int n,m,i=1,b[10];
string s;
char a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)cin>>a[i];
	while(i<=n){
		for(int j=i;j<=n;j++){
			s+=a[j];
			if(a[i]==a[j])s=a[j];
		}
		for(int i=0;i<s.size();i++)b[s[i]-'0']++;
	}
	for(int i=0;i<=9;i++)printf("%d ",b[i]);
	return 0;
}