#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,p1,p2,num=0,ans=0;
struct node{ll a;char c;}aa[200005];
ll p[200005]={0},s[200005]={0};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	p1=0,p2=n+1;
	for(int i=1;i<=n;i++){
		cin>>aa[i].a>>aa[i].c;
		p[i]=p[i-1]+aa[i].a;
	}for(int i=n;i>=1;i--)s[i]=s[i+1]+aa[i].a;
	while(p1<p2){
		p1++;
		if(p[p1]>p[n]/2)p[p1]=p[n]/2;
		while(p1<p2){
			if(num==s[p2])p2--;
			if(s[p2]>=p[p1]){
				if(aa[p1].c!=aa[p2].c)ans+=p[p1]-num;
				num=p[p1];
				break;
			}if(aa[p1].c!=aa[p2].c)ans+=s[p2]-num;
			num=s[p2];
		}
	}cout<<ans;
	return 0;
}
