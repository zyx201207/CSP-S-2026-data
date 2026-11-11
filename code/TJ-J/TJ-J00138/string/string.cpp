#include<bits/stdc++.h>
using namespace std;
struct nde{
	long long a;
	char c;
};
nde m[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m[i].a>>m[i].c;
	}
	long long l=1,r=n;
	long long ans=0;
	while(l<=r){
		if(m[l].a>m[r].a){
			if(m[l].c!=m[r].c){
				ans+=m[r].a;
			}
			m[l].a-=m[r].a;
			r--;
		}
		else if(m[l].a<m[r].a){
			if(m[l].c!=m[r].c){
				ans+=m[l].a;
			}
			m[r].a-=m[l].a;
			l++;
		}
		else if(m[l].a==m[r].a){
			if(m[l].c!=m[r].c){
				ans+=m[l].a;
			}
			l++;
			r--;
		}
		
	}
	cout<<ans;
	return 0;
} 
