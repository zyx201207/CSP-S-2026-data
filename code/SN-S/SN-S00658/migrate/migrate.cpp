//WA 0
#include<bits/stdc++.h>
#define fri(x,y) for(int i = x;i <= y;i++)
#define frj(x,y) for(int j = x;j <= y;j++)
#define lihaoming 0
#define ll long long
using namespace std;
int c,T;
ll n,d,ans;
ll a[310];
bool b[310][310];
ll f[310][310];
void dfs(int x){
	if(x > n){
		return;
	}
	fri(x + 1,n){
		if(a[i] - a[x] <= d){
			b[x][i] = 1;
			dfs(i);
		}
		else{
			return;
		}
	}
}
ll minn(int x,int y){
	ll cnt = 0;
	while(x < y){
		for(int i = y;i >= x;i--){
			if(i == x && !b[x][i]){
				return 0;
			}
			if(b[x][i]){
				x = i;
				cnt++;
				break;
			}
		}
	}
	return cnt;
}
int q_x,q_y;
ll q(int x,int y,int k){
	ll cnt = 0;
	if(x >= y){
		if(f[q_x][q_y] == k)
		return 1;
		return 0;
	}
	fri(x + 1,y){
		if(b[x][i]){
			cnt += q(i,y,k + 1);
		}
		else break;
	}
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans = 0;
		cin>>n>>d;
		fri(1,n){
			cin>>a[i];
		}
		dfs(1);
//		fri(1,n){
//			frj(1,n){
//				if(i >= j){
//					cout<<"- ";
//				}
//				else{
//					cout<<b[i][j]<<" ";
//				}
//			}
//			cout<<endl;
//		}
		fri(1,n){
			frj(1,n){
				if(i >= j){
//					cout<<"- ";
				}
				else{
					f[i][j] = minn(i,j);
//					cout<<f[i][j]<<" ";
				}
			}
//			cout<<endl;
		}
		fri(1,n){
			frj(i + 1,n){
				q_x = i,q_y = j;
				if(q(i,j,0) == 2){
//					cout<<i<<" -> "<<j<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return lihaoming;
}

