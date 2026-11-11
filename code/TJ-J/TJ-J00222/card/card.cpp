#include<bits/stdc++.h>

using namespace std;

#define int long long

int n,m,a[500005],b[500005],c[500005],bb;
bool f;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			f = 0;
			if(bb == 0){
				bb = 1;
				b[bb] = a[i];
			}else{
				f = 0;
				int x = bb;
				for(int k = 1;k <= bb;k++){
					if(a[i] == b[k]){
						f = 1;
						x = k;
					}else if(f == 1){
						b[i] = 0;
					}
				}
				bb = x;
			}
		}
		if(bb > 0){
			for(int j = 1;j <= bb;j++){
				c[b[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
} 
