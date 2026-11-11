#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
long long n,l,r;
long long ans=0,cnt=0;
struct node{
	long long siz;
	char cs;
}v[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>v[i].siz>>v[i].cs;
	}
	l=1;
	r=n;
	while(cnt<n){
		if(v[l].siz<v[r].siz){
			if(v[l].cs!=v[r].cs){
				ans+=v[l].siz;				
			}
			v[r].siz-=v[l].siz;
			v[l].siz=0;			
			l++;
			cnt++;
			continue;		
		}
		if(v[l].siz>v[r].siz){
			if(v[l].cs!=v[r].cs){
				ans+=v[r].siz;				
			}
			v[l].siz-=v[r].siz;
			v[r].siz=0;		
			r--;
			cnt++;
			continue;
		}
		if(v[l].siz==v[r].siz){
			if(v[l].cs!=v[r].cs){
				ans+=v[l].siz;				
			}
			v[r].siz=0;
			v[l].siz=0;
			l++;
			r--;
			cnt++;
			cnt++;
			continue;
		}		
	}
	cout<<ans;
	return 0;
}

