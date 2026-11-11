#include<bits/stdc++.h>
using nameespace std;
int n,m,a[10005],vis[100005];
struct node{
	z,x;
};
stack<node> b[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
    	cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i].top().z==1&&vis[b[a[i]].top.x])==1{
			cout << a[i];
		}
	}
	return 0;
}
