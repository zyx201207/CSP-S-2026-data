#include<bits/stdc++.h>
using namespace std;
long long n,ans,l,r;
struct{
	int num;
	char f;
}m[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i].num>>m[i].f;
	}
	l=1;r=n;
	while(l<r){
		int x=min(m[l].num,m[r].num);
		if(m[l].num==m[r].num){
			if(m[l].f!=m[r].f){
				ans+=x;
			}
			l++;
			r--;
			
		}
		else if(x==m[l].num){
			if(m[l].f!=m[r].f){
				ans+=x;
			}
			l++;
			m[r].num-=x;
			
		}
		else if(x==m[r].num){
			if(m[l].f!=m[r].f){
				ans+=x;
			}
			r--;
			m[l].num-=x;
			
		}
	}
	cout<<ans;
	return 0;
}
