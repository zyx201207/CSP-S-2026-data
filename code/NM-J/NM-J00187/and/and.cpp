#include <bits/stdc++.h>
#define a first 
#define b second
using namespace std;
int n,m,ans,p[32]={1},b[200200];
pair<int,int>a[200200];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i].a;
	for(int i=1;i<=29;i++)  p[i]=p[i-1]*2;
	sort(a+1,a+1+n);
	for(int i=29;i>=0;i--){
		int bg=0,f=0;
		for(int j=n;j>=1;j--){
			if(((a[j].a&p[i])<p[i])||(a[j].b<ans)){
				if(a[j].a<p[i])  break;
				continue;
			}
		        bg++,b[++f]=j;
		}
		if(bg>=m){
			ans+=p[i];
			for(int k=1;k<=f;k++)  a[b[k]].b+=p[i];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

