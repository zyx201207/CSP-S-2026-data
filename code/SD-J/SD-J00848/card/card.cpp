#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=-1,b[100005]={0},c[100005],po[100005];
string s;
char a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&po[i]);
		a[i]=char(po[i]+48);
	}
	for(int i=1;i<=n;i++){
		s="";
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			if(s.find(a[j])!=-1){
				s=s.substr(0,s.find(a[j])+1);
			}
			else{
				
				s+=a[j];
			}
		}
		for(int j=0;j<s.size();j++){
			c[s[j]-48]++;
		}
		for(int j=1;j<=m;j++){
			if(c[j]>0){
				b[j]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",b[i]);
	}
	return 0;
}
