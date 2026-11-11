#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define endl '\n'
#define ll long long

int a[500005];
int flag[500005];
int ma[500005];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n,m; cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		
		string tmp;
		
		for(int j=i;j<=n;j++){
			
			if(flag[a[j]]!=0){
				
				int Begin=flag[a[j]]-1;
				int End=j-1;
				
				tmp=tmp+char(a[j]+'0');
				if(End>=0 && tmp.size()>=End-Begin)
					tmp.erase(Begin,End);
					
			}else tmp=tmp+char(a[j]+'0');
			flag[a[j]]=j;
		}
		
		for(int j=0;j<tmp.size();j++){
			int x=int(tmp[j]-'0');
			ma[x]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ma[i]<<" ";
	 
	return 0;
}
