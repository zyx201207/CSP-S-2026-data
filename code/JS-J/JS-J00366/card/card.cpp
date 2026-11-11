#include<bits/stdc++.h>
using namespace std;
int a[10000005],t[10000005],mn[1000005],s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		memset(mn,0,sizeof(mn));
		s=0;
		for(int x=i;x<=n;x++){
			bool f=0;
			for(int j=1;j<s;j++){
				if(a[j]==a[x]){
					s=j;
					f=1;
					break;
				}
			}if(!f){
				s++;
				mn[s+1]=a[x];
			}
		}for(int x=1;x<=s;x++){
			t[mn[x]+1]++;
		}
	}for(int i=1;i<=n;i--){
		cout<<t[i]<<' ';
	}return 0;
}
