#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=2e6+5,mod=998244353;
int c,t;
int n,d;
int x[N];
int l[N],r[N];
int ld[N],rd[N];
map<PII,bool>mp;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int lst=1;
		l[1]=1;
		for(int i=1;i<=n;i++){
			while(x[lst+1]-x[i]<=d&&lst!=n)lst++,l[lst]=i;
			r[i]=lst;
		}
		ld[1]=1;
		for(int i=2;i<=n;i++){
			ld[i]=l[i]-l[i-1]+ld[l[i]];
		}
		rd[n]=1;
		for(int i=n-1;i>=1;i--){
			rd[i]=r[i+1]-r[i]+rd[r[i]];
		}
//		for(int i=1;i<=n;i++){
//			cout<<l[i]<<' '<<r[i]<<'\n';
////			cout<<ld[i]<<' '<<rd[i]<<'\n';
//		}
		int ans=0;
		for(int i=1;i<=n-1;i++){
//			if(l[i]==l[i+1]&&r[i]==r[i+1]&&(i==1||(l[i-1]!=l[i]||r[i-1]!=r[i]))&&(i+1==n||(r[i+2]!=r[i+1]||l[i+2]!=l[i+1]))){
//				ans+=ld[i]*rd[i+1];
//				cout<<1;
//			}
			if(l[i]==l[i+1]){
				for(int j=max(i+1,r[l[i]])+1;j<=r[i];j++){
					if(mp[{l[i],j}]==0){
						ans++;
					}
					mp[{l[i],j}]=1;
				}
			}
			if(r[i]==r[i+1]){
				for(int j=l[i+1];j<=min(i,l[r[i]])-1;j++){
					if(mp[{j,r[i]}]==0){
						ans++;
					}
					mp[{j,r[i]}]=1;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

/*
//freopen
frepen
fropen
j0 j1 jn
y0 y1 yn
bits\stdc++.h
#include<bits\stdc++.h>
4 2
63p/min
1=C
      . .      
6 3 6 1 1 3 6 3 |
`     
      . .       
6 3 6 1 1 3 6 3 |
`               

3 2 3 7 7 3#5 3 |
`

3 2 3 7 7 2 3 2 |
`
      . .      
1 3 6 1 1 3 6 3 |


4 1 4 6 6 1 4 1 |
` 

3 7 3#5#5 7 3 7 |
` `       `   `
  _   _    \    /  v   /   \       /   \  /     _
shan'dong'wai'guo'yu'xue'xiao'de'shen'mi'ling'sheng
*/
//14:30-14:48 T1 100pts
//14:48-15:55 T2 80pts-100pts 
//16:00-??? T3 0pts
//T4 15pts
//qwq 195~215
