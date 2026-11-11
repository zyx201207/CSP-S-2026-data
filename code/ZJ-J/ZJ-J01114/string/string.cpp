#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	long long a;
	char s;
}m[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i].a;
		cin>>m[i].s;
	}
	long long l=1,r=n;
	long long ans=0;
	while(1){
		if(l==r){
			break;
		}
		if(m[l].s!=m[r].s){
			ans+=min(m[l].a,m[r].a);
			if(m[l].a<m[r].a){
				m[r].a-=m[l].a;
				l++;
			}
			else if(m[l].a>m[r].a){
				m[l].a-=m[r].a;
				r--;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(m[l].a<m[r].a){
				m[r].a-=m[l].a;
				l++;
			}
			else if(m[l].a>m[r].a){
				m[l].a-=m[r].a;
				r--;
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}