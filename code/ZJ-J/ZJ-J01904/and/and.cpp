#include<bits/stdc++.h>
using namespace std;
int n,m,a,cnt[200005],k=-1,ans=1;
string s[200005],t[200005];
bool cmp(string s1,string s2){return s1>s2;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		while(a){
			if(a&1)s[i]="1"+s[i];
			else s[i]="0"+s[i];
			a>>=1;
		}
		int l=s[i].size();
		for(int j=l;j<30;j++)s[i]="0"+s[i];
		for(int j=0;j<30;j++)cnt[30-j-1]+=s[i][j]-'0';
	}
	for(int i=29;i>=0;i--)
		if(cnt[i]>=m){k=i;break;}
	if(k==-1){printf("0");return 0;}
	for(int i=1;i<=n;i++)t[i]=s[i].substr(29-k,k+1);
	sort(t+1,t+n+1,cmp);
	n=cnt[k];
	for(int i=k-1;i>=0;i--){
		ans*=2;
		int x=0;
		for(int j=1;j<=n;j++)t[j].erase(0,1);
		for(int j=1;j<=n;j++)x+=t[j][0]-'0';
		if(x>=m)ans++,sort(t+1,t+n+1,cmp),n=x;
	}
	printf("%d",ans);
	return 0;
}
