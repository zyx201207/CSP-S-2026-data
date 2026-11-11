#include<bits/stdc++.h>
using namespace std;
#define int long long
#define repr(i,a,b) for(int i = a;i <= b;i++)
const int MAXN = 5005;
int a[MAXN],b[MAXN];
int maxn[MAXN][MAXN];
int sum[MAXN][MAXN];
int n,m;
int ans = 0;
void checkA(){
	int sum = 0;
	repr(i,1,n){
	    if(sum<m){
			ans++;
		}
		sum+=a[i];
	}
	cout<<ans<<endl;
}
void checkB(){
	b[1] = a[1];
	b[2] = a[2]-a[1];
	repr(i,3,n){
		b[i] = b[i-1]+(i-1)*(b[2]);
	}
	repr(i,1,n){
		if(b[i]<=m){
			ans = i;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	cin>>n>>m;
	bool flaga = true;
	bool flagb = true;
	repr(i,1,n){
		cin>>a[i];
		if(a[i]!=i) flaga = false;
	}
	if(!flaga){
		int d = a[2]-a[1];
		repr(i,2,n){
			if(d!=a[i]-a[i-1]){
				flagb = false;
			}
		}
	}
	if(!flaga&&!flagb){
		for(int l = 1;l <= n;l++){
			for(int r = l;r <= n;r++){
				maxn[l][r] = max(maxn[l][r-1],a[r]);
			}
		}
	//	repr(i,1,n){
	//		repr(j,i,n){
	//			cout<<maxn[i][j]<<" ";
	//		}
	//	}
		repr(l,1,n){
			repr(r,l,n){
				int x = l,y = r;
				while(x<=y){
					sum[l][r] += (maxn[l][r]-a[x]);
					x++;
				}
			}
		}
		repr(i,1,n){
			repr(j,1,n){
				if(sum[i][j]<=m){
					ans = max(ans,j-i+1);
				}
			}
		}
		cout<<ans<<endl;
	}
	if(flaga) checkA();
	if(flagb&&flaga==false) checkB();
//	repr(i,1,n){
//		b[i] = a[i+1]-a[i];
//	}
//	repr(i,1,n-1){
//		b[i]+=b[i-1];
//	}
//	int ans = -1;
//	int lst = 0;
//	repr(i,1,n-1){
//		int l = i,r = n-1;
//		int mid = (l+r)>>1;
//		while(l<=r){
//			mid = (l+r)>>1;
//			if(b[mid]-b[i]<=m){
//				l = mid+1;
//				lst = mid;
//			}
//			else r = mid-1;
//		}
//		
//		ans = max(ans,mid-i+1);
//	}
//	cout<<ans<<endl;
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/
