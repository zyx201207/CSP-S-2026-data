#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct node{
	long long a;
	char b;
} q[200006];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].b;
	}
	int z=n;
	for(int i=1;i<=n;i++){
		if(i>=z) break;
		if(q[i].a == 0){
			continue;
		}else{
			while(q[i].a>0){
				int y=min(q[i].a,q[z].a);
				if(q[z].b == q[i].b){
					q[i].a-=y;
					q[z].a-=y;
				}else{
					ans+=y;
					q[i].a-=y;
					q[z].a-=y;
				}
				if(q[z].a<=0){
					z--;
				}
			}
		}
	}
	cout<<ans;
    return 0;
}
