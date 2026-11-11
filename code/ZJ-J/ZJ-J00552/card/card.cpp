#include<bits/stdc++.h>
using namespace std;
int a[500005];
queue<int> t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		int ans=0;
		for(int j=i;j<=n;j++){
			int k=a[j];
			int d=0;
			for(int l=0;l<t.size();l++){
				int e=t.front();
				t.pop();
				t.push(e);
				if(e==k){
					queue<int> t1;
					while(t.empty()){
						t1.push(t.front());
						t.pop();
					}
					while(t1.empty()){
						if(t1.front()==e){
							break;
						}
						t.push(t1.front());
						t1.pop();
					}
					break;
				}
				if(e==i){
					d=1;
				}
			}
			ans+=d;
			t.push(k);
		}
		if(ans){
			cout<<ans<<" ";
		}
	}
	return 0;
}