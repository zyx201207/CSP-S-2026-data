#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int a[N];
bool vis[10001][10001];
int ans;
int test=N;
bool flag=0;
int q;
int l[N];
/*
0 2
4 2
1 2 3 4
5 2 
1 2 3 4 5
*/
void inside(int start,int end,int time){
	if(time>test){
//		for(int i=1;i<=time;i++){
//			cout<<l[i]<<' ';
//		}cout<<endl;
//		cout<<"O GOD"<<endl;
		return ;
	}
	if(q>2){
//		cout<<"O NO"<<endl;
		return ;
	}
	if(start==end){
		if(!flag){
			flag=1;
//			cout<<"KSKBL"<<endl;
			q++;
			test=time;
			return ;
		}else{
//			cout<<"ZDJD"<<endl;
			if(time==test){
//				cout<<"WK ZKBL"<<endl;
				q++;
				return ;
			}else{
//				cout<<"Äãµô½øÏÝÚåÁË"<<endl;
				return ;
			}
		}
		return ;
	}
	for(int i=end;i>start;i--){
		if(vis[start][i]){
			l[time+1]=i;
			inside(i,end,time+1);
		}
	}
}
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vis[i][j]=vis[j][i]=abs(a[j]-a[i])<=d;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<vis[i][j]<<' ';
//		}cout<<endl;
//	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(vis[i][j]){
				continue;
			}else{
//				cout<<i<<' '<<j<<endl;
				q=0;
				flag=0;
				test=N;
				l[1]=i;
				inside(i,j,0);
//				cout<<q<<endl;
				if(q==2){
					ans++;
				}
			}
		}
	}cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		flag=0;
		q=0;
		test=N;
		solve();
	}
	return 0;
}

