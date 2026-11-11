#include<iostream>
#define F(i,k,n) for(int i=(k);i<=(n);++i)
#define RF(i,n,k) for(int i=(n);i>=(k);--i)
#define LL long long
#define ULL unsigned long long
using namespace std;
LL n;
LL d;
LL a[2000005];
int dis[5005][5005];
int cnt[5005][5005];
void solve1(void){
	d/=(a[2]-a[1]);
	//cout<<a[2]-a[1]<<' '<<d;
	if(d<=1){
		cout<<0<<'\n';
	}else{
		cout<<max(0LL,n-2*d+1)<<'\n';
	}
	return;
}
void solve2(void){
	int ans=0;
	F(i,1,n){
		dis[i][i]=0;
		cnt[i][i]=1;
		F(j,i+1,n){
			dis[i][j]=1e9;
			cnt[i][j]=0;
			F(k,i,j-1){
				if(a[j]-a[k]<=d){
					if(dis[i][k]+1<dis[i][j]){
						dis[i][j]=dis[i][k]+1;
						cnt[i][j]=cnt[i][k];
					}else if(dis[i][k]+1==dis[i][j]){
						cnt[i][j]+=cnt[i][k];
						if(cnt[i][j]>3){
							cnt[i][j]=3;
						}
					}
				}
			}
			//cout<<i<<' '<<j<<' '<<dis[i][j]<<' '<<cnt[i][j]<<'\n';
			if(cnt[i][j]==2){
				++ans;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,_;
	cin>>c>>_;
	while(_--){
		cin>>n>>d;
		F(i,1,n){
			cin>>a[i];
		}
		if(n<=2){
			cout<<0<<'\n';
			continue;
		}
		if(c==11||c==12){
			solve1();
		}else{
			solve2();
		}
	}
	return 0;
}
/*
11 1
5 3 
-2 -1 0 1 2

11 1
10 222222222222222208
-999999999999999936 -777777777777777728 -555555555555555520 -333333333333333312 -111111111111111104 111111111111111104 333333333333333312 555555555555555520 777777777777777728 999999999999999936

0 2 
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
6 3
0 1 2 3 4 7


11 1
10 31746031746031745
-1000000000000000000 -777777777777777785 -555555555555555570 -333333333333333355 -111111111111111140 111111111111111075 333333333333333290 555555555555555505 777777777777777720 999999999999999935

32pts
*/