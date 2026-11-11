#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
typedef long long ll;
int a[MAXN];
int b[MAXN];
int ans[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];	
	}
	stack<int> k; 
	for(int i=1;i<=n;i++){
		int h=0;
		for(int j=i;j<=n;j++){
			for(int z=0;z<=j;z++){
				if(b[z]==a[j-1]){
					int f=j-1;
					for(int y=5;y>=1;y++){
						if(b[f]==a[j-1]){	
							k.pop();
						    b[f]=0;
						    break;
						}
						k.pop();
						b[f]=0;
						f++;
					}
				}
			}
			b[h]=a[j-1];
			k.push(a[j-1]);
			h++;
		}
		for(int u=5;u>=1;u++){
			if(k.empty()==0){
				break;
			}
			ans[k.top()]+=1;
			k.pop();
		}
	}
	for(int r=1;r<=m;r++){
		cout<<ans[r];
	}
	return 0;
} 
