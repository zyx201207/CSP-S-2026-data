#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;

struct Node{
	bool bt[40];
	int num;
}s[MAXN];

int n,m;
int cnt[40];
int ans;

int lowbit(int x){return x&(-x);}

bool cmp(Node a,Node b){
	for(int k=30;k>=1;k--) if(a.bt[k]!=b.bt[k]) return a.bt[k]>b.bt[k];
	return 0;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		s[i].num=a;
		int k=1;
		while(a!=0){
			if(lowbit(a)==1) s[i].bt[k]=1,cnt[k]++;
			a>>=1,k++;
		}
	}
	for(int k=1;k<=30;k++){
		if(cnt[k]>=m) continue;
		for(int i=1;i<=n;i++) s[i].bt[k]=0;
	}
	sort(s+1,s+n+1,cmp);
	ans=s[1].num;
	for(int i=1;i<=m;i++) ans&=s[i].num;
	cout<<ans;
	return 0;
}
