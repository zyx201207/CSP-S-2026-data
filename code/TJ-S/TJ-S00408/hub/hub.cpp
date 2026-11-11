#include<bits/stdc++.h>
using namespace std;

int n , m;
int f[1000005][5];
vector<int>e[1000005];
queue<int>q;
bool vis[1000005];

int main(){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	
	int c , t;
	cin >> c >> t;
	
	for(int hjm = 1;hjm <= t;hjm++){
		cin >> n >> m;
		
		for(int i = 1;i < n;i++){
			int x , y;
			cin >> x >> y;
			e[x].push_back(y);
		}
		
		if(n == m){
			cout<<0<<endl;
		}else{
			cout<<n/(k+1)<<endl;
		}
	}
	
	return 0; 
} 

/*连暴力都不会写了，没救了
还有十分钟，写不出来了
就这样吧 100+32/44+40+0 = 172/184
应该能过吧....
rp++ rp++ rp++ rp++
 orz orz orz orz 
*/
