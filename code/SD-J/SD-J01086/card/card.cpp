#include<bits/stdc++.h>
using namespace std;
int a[5000000];
int ans[5000000];
string b="";
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int y;
		cin>>y;
		a[i]=y;
	}
	int idx=1; 
	for(int i=1;i<=n;i++){
		for(int j=idx;j<=n;j++){
			char c=a[j]+'0';
			bool f=true;
			for(int k=0;k<b.size();k++){
				if(b[k]==c){
					f=false;
					string g=b;
					b="";
					for(int l=0;l<=k;l++){
						b+=g[l];
					}
					break;
				}
			}
			if(f){
				b=b+c;
			}
		}
		for(int j=1;j<=m;j++){
			char c=j+'0';
			for(int k=0;k<b.size();k++){
				if(b[k]==c){
					ans[j]++;
					break;
				}
			}			
		}
		idx++;
		b="";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
