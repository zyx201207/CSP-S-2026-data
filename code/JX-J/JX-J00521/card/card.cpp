#include<bits/stdc++.h>
using namespace std;
const int MAXN=500001;
int a[MAXN],a1[MAXN],c[MAXN];
bool b1[MAXN],b2[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,t;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=a[i];
	}
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			if(b1[a1[i]]==true){
				for(int j=1;j<i;j++)
					if(a1[j]==a1[i]){
						t=j;
						break;
					}
				for(int k=t;k<i;k++)
					a1[k]=0;
			}else b1[a1[i]]=true;
		}for(int i=l;i<=n;i++){
			if(a1[i]!=0){
				c[a1[i]]++;
			}
		}for(int i=1;i<=n;i++){
			b2[i]=0,b1[i]=0,a1[i]=a[i];
		}
	}for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
	return 0;
}
