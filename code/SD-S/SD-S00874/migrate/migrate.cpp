#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long

int x[200005];
vector<int> e[200005];

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int c,t;
	cin>>c>>t;
	
	while(t--){
		int n,d; cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
			
		int Cha=0,lasCha=0,flag=0;
		for(int i=2;i<=n;i++){
			Cha=x[i]-x[i-1];
			if(i!=2 && Cha!=lasCha){
				flag=1;
				break;
			}
			lasCha=Cha;
		}
			
		if(flag==0)
			cout<<n-(d+1)<<endl;
	}
	
	return 0;
}
