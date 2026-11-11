#include<bits/stdc++.h>
using namespace std;
map<int,int>pp;
const int N=5e5+10;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int q=n;
	for(int i=1;i<=q;i++){
		map<int,int>mp;
		int s[N]={0};
		int d=0;
		int f=1;
		for(int j=f;j<=n;j++){
			if(mp[a[j]]>0){
				int b=0;
				for(int z=j-1;z>=f;z--){
					b++;
					if(s[z]!=a[j]){
						s[z]=0;
					}else{
						d-=b;
						d+=1;
						s[z]=0;
						break;
					}
				}
				s[++d]=a[j];
			}else{
				mp[a[j]]++; 
				s[++d]=a[j];
			}
		}
		f++;
		for(int j=1;j<=m;j++){
			pp[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<pp[i]<<" "; 
	} 
	return 0;
} 
