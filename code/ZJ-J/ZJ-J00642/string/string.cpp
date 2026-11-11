#include<bits/stdc++.h>
using namespace std;
struct cp{
	long long a;
	char c;
} s[200005],st[200005],str[200005];
long long n,ans,k,sum,q[30],maxx;
char t,ak;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1 ;i<=n; i++){
		cin>>s[i].a>>s[i].c;
		if(s[i].c==t){
			s[ans].a+=s[i].a,s[i].a=0;
		}
		else ans=i,t=s[i].c;
	}
	for(int i=1; i<=n; i++){
		if(s[i].a!=0)st[++k].a=s[i].a,st[k].c=s[i].c;
	}
	if(k==1){
		cout<<0;
		return 0;
	} 
	for(int i=k; i>=1; i--){
		str[i].a=st[k-i+1].a;
		str[i].c=st[k-i+1].c;
	}
	int flag=1;
	for(int i=1; i<=k; i++){
		sum+=str[i].a;
		if(str[i].a!=st[i].a||str[i].c!=st[i].c){
			flag=0;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=1; i<=k; i++){
		q[int(st[i].c-'a'+1)]=st[i].a;
	}
	for(int i=1; i<=29; i++) {
		if(q[i]>maxx){
			maxx=q[i],ak=char(i+'a'-1);
		}
	}
	if(sum%2==0) cout<<sum-maxx;
	else{
		long long p=sum/2+1,flag=1;
		for(int i=1; i<=k; i++){
			p-=st[i].a;
			if(p<=0){
				if(st[i].c==ak){
					flag=0;
				}
				break;
			}
		}
		if(flag) cout<<sum-maxx-1;
		else cout<<sum-maxx;
	}
	return 0;
}
