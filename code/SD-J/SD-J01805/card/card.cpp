#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool place[300005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
    	cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		queue<int> q;
		for (int j = i;j <= n;j++){
			if(place[a[j]] == true){
				while(q.front() != a[j]){
					place[q.front()] = false;
					q.pop();
				}
			}else{
				q.push(a[j]);
				place[a[j]] = true;
            }
	    	while (!q.empty()){
			    ans[q.front()]++;
			    place[a[j]] = false;
		    	q.pop(); 
	    	}
	    }
	}
	for (int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	} 
	return 0;
} 
