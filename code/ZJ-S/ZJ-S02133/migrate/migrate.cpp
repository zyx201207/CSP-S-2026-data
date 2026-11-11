#include<bits/stdc++.h>
#define N 2000005
typedef long long ll;
using namespace std;

int x[N];
int n,c,T;
vector<int> u[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i++){
			scanf("%d",&x[i]);
		}
		for(int i = 1 ; i <= n ; i++){
			int j = i + 1;
			while(x[j] - x[i] <= d){
				u[i].push_back(j);
				j++;
			}
		}
	}
	
	
	return 0;
}
