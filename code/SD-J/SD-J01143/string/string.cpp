#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+10;
struct ac{
	long long a;
	string c;
}q[N];
long long ans,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].c;
	}
	long long l=1,r=n;
	while(l<=r){
		if(q[l].c==q[r].c){
			if(q[l].a>q[r].a){
				q[l].a-=q[r].a;
				r--;
			}else if(q[l].a<q[r].a){
				q[r].a-=q[l].a;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(q[l].a>q[r].a){
				ans+=q[r].a;
				q[l].a-=q[r].a;
				r--;
			}else if(q[l].a<q[r].a){
				ans+=q[l].a;
				q[r].a-=q[l].a;
				l++;
			}else{
				ans+=q[l].a;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
