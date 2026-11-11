#include<bits/stdc++.h>
using namespace std;
#define int long long

string c1,s1,c2,s2;
int cnt;
int vis[10]={0,0,0,1,1};
int v[10]={1,2,3,5,6};

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F') s1[2]='E';
	if(s2[2]=='F') s2[2]='E';
	if(c1==c2){
		cout<<1;
		cnt++;
	}
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&cnt==1){
		cout<<1;
		cnt++;
	}
	else cout<<0;
	int a=s1[2]-'A';
	int b=s2[2]-'A';
	if(vis[a]==vis[b]&&cnt==2){
		cout<<1;
		cnt++;
	}
	else cout<<0;
	if(abs(v[a]-v[b])==1&&cnt==3) cout<<1;
	else cout<<0;
	return 0;
} 
