#include<bits/stdc++.h>
using namespace std;
const int Maxn=2005;
int n;
long long ans=0;
struct hs{
	int a;
	char c;
}p[Maxn];
int main(){
	freopen("string5.in","r",stdin);
	freopen("string5.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(p[l].c==p[r].c){
			if(p[l].a>p[r].a){
				p[l].a-=p[r].a;
				p[r].a=0;
				r--;
			}
			else if(p[l].a<p[r].a){
				p[r].a-=p[l].a;
				p[l].a=0;
				l++;
			}
			else{
				l++;
				r--;
				if(p[r-1].a==0||p[l+1].a==0){
					break;
				}
				
			}
		}
		else{
			ans+=min(p[l].a,p[r].a);
			if(p[l].a>p[r].a){
				p[l].a-=p[r].a;
				p[r].a=0;
				r--;
			}
			else if(p[l].a<p[r].a){
				p[r].a-=p[l].a;
				p[l].a=0;
				l++;
			}
			else{
				p[l].a=0,p[r].a=0;
				l++;
				r--;
				if(p[r-1].a==0||p[l+1].a==0){
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
