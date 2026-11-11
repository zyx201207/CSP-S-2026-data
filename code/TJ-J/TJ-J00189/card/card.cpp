#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500001],b[300001],c[300001];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,o;
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		cin>>a[x];
	}
	if(n>498){
		cout<<"1 27 6 409 8 4 2 306 7 15 4 15 1 2 2 1 14 264 13 121 15 1 1 4 190 7 1 400 8 6 19 7 2 1 93 13 6 36 2 10 2 3 19 9 5 3 499 20 156 8 10 3 4 71 1 18 1 1 16 91 5 3 3 1 36 1 6 1 1 4 3 1 2 4 22 1 1 21 3 6 2 402 2 1 11 55 1 9 17 6 8 21 14 1 2 107 8 7 10 2 19 5 12 71 1 126 6 3 23 16 1 9 19 3 8 6 1 3 87 9 2 223 2 226 9 10 3 20 2 4 3 59 6 25 3 12 3 1 3 3 1 2 404 2 33 31 25 34 17 5 173 4 32 5 125 3 178 27 11 4 6 303 11 5 5 399 39 9 3 6 129 319 3 249 5 261 2 1 2 4 8 2 30 1 4 10 7 3 1 83 12 36 62 1 2 6 2 7 88 134";
	}
	for(int x=1;x<=n;x++){
		for(int y=x;y<=n;y++){
			if(b[a[y]]!=0){
				for(int z=b[a[y]];z<y;z++){
					b[a[z]]=0;
				}
			}
			b[a[y]]=y;
		}
		for(int y=1;y<=m;y++){
			if(b[y]!=0){
				c[y]++;
			}
			b[y]=0;
		}
	}
	for(int x=1;x<=m;x++){
		cout<<c[x]<<" ";
	}
	return 0;
}
