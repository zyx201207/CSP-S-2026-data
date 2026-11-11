#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char c;
};
vector<node> v; 
int main(){
	// qian nian de wang ba , wan nian de gui . she zhang wan sui ! ! !
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 long long sum=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		sum+=x;
		v.push_back({x,c});
	}
	long long ws=v.back().x; 
	char wc=v.back().c;
	long long yj=0;
	int j=n-1;
	long long ans=0;
	for(int i=0;i<n;i++){ 
		long long x=v[i].x;
		char c=v[i].c;
		if(sum/2ll-yj>x){
			while(x>0){
				if(ws>x){
					ws-=x;
					if(c!=wc) ans+=x;
					yj+=x;
					break;
				}else{
					x-=ws;
					if(c!=wc) ans+=ws;
					j--;
					yj+=ws;
					ws=v[j].x;
					wc=v[j].c;
				}
			}
		}else{
			long long s=sum/2ll-yj;
			while(s>0){
				if(ws>s){
					ws-=s;
					if(c!=wc) ans+=s;
					yj+=s;
					break;
				}else{
					s-=ws;
					if(c!=wc) ans+=ws;
					j--;
					yj+=ws;
					ws=v[j].x;
					wc=v[j].c;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	cout<<ans; 
	return 0;
} 
