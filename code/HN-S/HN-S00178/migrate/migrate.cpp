#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,d;
int c,t;//tÎª×éÊý
vector<int> a;
vector<int> b;
vector<int> c;
void dfs(int s){
	
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		a.clear();
		b.clear();
		a.resize(n+1);
		b.resize(n+1);
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=n;j>=1;j--){
			for(int s=j-1;j>=1;j--){
			if(a[s]-a[j]>=d){
				b[j]++;
				}
			}
		}
		
		
	}
}
