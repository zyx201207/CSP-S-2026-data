#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int MAX=5e5+5;
int n,m;
int a[MAX];
map<int,int>mp;
bool flag[MAX];
string s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof flag);
		s="";
		for(int j=i;j<=n;j++){
			int flg=0,wei=0;
			int len=s.size();
			for(int k=0;k<len;k++){
				if((s[k]==(char)(a[j]+'0'))&&flag[k]==1){
					flg=1;
					wei=k;
					break;
				}
				if(s[0]==(char)(a[j]+'0')){
				}
			}
			if(flg){
				for(int k=wei;k<len;k++){
					flag[k]=0;
				}
				s=s+(char)(a[j]+'0');
				int lin=s.size();
				flag[lin-1]=1;
			}else{
				s=s+(char)(a[j]+'0');
				int lin=s.size();
				flag[lin-1]=1;
			}
		}
		int len=s.size();
		for(int j=0;j<len;j++){
			if(flag[j]==1){
				mp[s[j]-'0']++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<' '; 
	}
	return 0;
}
