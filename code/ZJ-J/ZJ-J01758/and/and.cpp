#include<bits/stdc++.h>
using namespace std;
long long a,b,c,e[50],s1[40],s;
bool d[200005][40],f[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c;
		int t=0;
		while(c){
			d[i][++t]=c%2;
			e[t]+=d[i][t];
			c/=2; 
//			cout<<d[i][t];
		}
	}
	for(int i=30;i>=1;i--){
		if(e[i]>=b){
			s1[i]=1;
			for(int j=1;j<=a;j++) f[j]=d[j][i];
			for(int j=i-1;j>=1;j--){
				int t=0;
				for(int z=1;z<=a;z++) if(f[z]) t+=d[z][j];
				if(t>=b){
					for(int z=1;z<=a;z++) if(f[z]) f[z]=d[z][j];
					s1[j]=1;
				}
			}break;
		}
	}for(int i=30;i>=1;i--) s=s*2+s1[i];
	cout<<s;
	return 0; 
}
