#include<bits/stdc++.h>
using namespace std;
#define lint long long
struct node{
	lint a;
	char b;
};
lint n,ans;
node q[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].b;
	}
	lint l=1;
	lint r=n;
	while(l<=r){
		lint x=q[l].a;
		lint y=q[r].a;
		if(x>y){
			if(q[l].b==q[r].b){
				q[l].a=x-y;
				r--;	
			}
			else{
				q[l].a=x-y;
				r--;
				ans+=y;
			}
		}
		else if(x==y){
			if(q[l].b==q[r].b){
				l++;
				r--;	
			}
			else{
				l++;
				r--;
				ans+=x;
			}
		}
		else{
			if(q[l].b==q[r].b){
				q[r].a=y-x;
				l++;	
			}
			else{
				q[r].a=y-x;
				l++;
				ans+=x;
			}
		} 
	}
	cout<<ans;
	return 0;
}
