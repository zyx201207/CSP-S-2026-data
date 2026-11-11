#include<bits/stdc++.h>
using namespace std;
int n,m,t[200005],b[35],cnt[35],ans,k=1;
bool f;
bool cmp(int a,int b){
	return a>b;
}
struct q{
	int p;
	int c;
}s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>t[i];
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=31;i++) b[i]=pow(2,i);
	for(int i=1;i<=31;i++){
		for(int j=1;j<=n;j++){
			if(t[j]>=b[i]&&t[j]<b[i+1]){
				if(t[i]!=b[i+1]-1) f=1;
				s[j].p=t[j];
				s[j].c=i+1;
			}
		}
	}
	if(!f){
		cout<<22;
		ans=s[1].p;
		for(int i=2;i<=m;i++){
			ans&=s[i].p;
		}cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i].c<s[k].c) k=i;
		if(s[i].c==s[k].c)cnt[s[k].c]++;
	}
	for(int i=1;i<=n;i++){
		if(cnt[s[i].c]>1){
			ans=s[i].p;
			break;
		}
	}
	for(int i=2;i<=m;i++)
		ans&=s[i].p;
	cout<<ans;
	return 0;
}

