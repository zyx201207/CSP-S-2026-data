#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
const int N = 5e5+10;
int n,m,arr[N],vis[N],cnt,ans[N],a[N],l,r;
stack<int> s,p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i = 1;i <= n;i++){
		memset(vis,0,sizeof(vis)); 
		memset(a,0,sizeof(a));
		r = 0;
		for(int j = i;j <= n;j++){
			if(!vis[arr[j]]){ a[++r]=arr[j]; vis[arr[j]] = 1;
			}else{ 
				while(a[r] != arr[j] && r > 0){
					a[r] = 0;r--;
				}
//				cout << "\nDel\n";
			}
//			for(int k = 1;k <= r;k++){
//				cout << a[k] << ' ';
//			}
//			cout << r <<endl;
//			printf("\nfff:i=%d,j=%d,arr[j]=%d,vis[arr[j]]=%d,s.size()=%d\n",i,j,arr[j],vis[arr[j]],s.size());
		}
//		cout << "\n---\n";
//		while(!s.empty()){ ans[s.top()]++;cout << s.top() << ' '; s.pop(); }
		for(int j = 1;j <= m;j++){
			ans[j] += vis[j];
			
		}
	}
	for(int i = 1;i <= m;i++){ printf("%d ",ans[i]); }
	return 0;
}
