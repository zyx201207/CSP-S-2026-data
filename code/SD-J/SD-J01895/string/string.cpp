#include<bits/stdc++.h>
using namespace std;
string str;
char ch[10001],c;
int n,a,sum=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		cin>>a>>c;
		sum+=a;
		for(int i=sum-a;i<=sum;++i){
			ch[i]=c;
		}
	}
	for(int i=1;i<=sum/2;++i){
		int j=sum;
		if(ch[i]!=ch[j]) ans++;
	}
	printf("%d\n",ans);
	return 0;
} 
