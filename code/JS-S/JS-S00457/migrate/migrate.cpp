#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <queue>
#define edge pair<int,long long>
#define mp make_pair
#define maxn 2635999
using namespace std;
typedef long long ll;
int c,t;
int n;
ll d;
ll x[maxn];
vector<int> cc[maxn];
int tot=0;
ll ans=0;
void solve(int i){
	
}
int main() {
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ll lst=x[1];
		cc[tot].push_back(1);
		for(int i=2;i<=n;i++){
			if(x[i]-lst>d){
				cc[++tot].push_back(i);
			}
			else{
				cc[tot].push_back(i);
			}
			lst=x[i];
		}
		for(int i=0;i<=tot;i++){
			solve(i);
		}
		cout<<ans<<endl;
	}
}