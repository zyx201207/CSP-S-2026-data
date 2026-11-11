#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
struct o{
	long long a;
	char b;	
};
o c[200005],d[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::cin>>d[i].a>>d[i].b;
		d[i].a+=d[i-1].a;
		
	}
	int g;
	for(int i=1;i<=n;i++){
		if(d[i].a<=d[n].a/2){
			c[i].a=d[i].a;
			c[i].b=d[i].b;
			continue;
		}
		if(d[i-1].a<=d[n].a/2 && d[i].a>=d[n].a/2){
			g=i-1;
			if(d[i-1].a+1<d[n].a/2 && d[i].a>d[n].a/2+1){
				c[n+2].a=d[n].a/2;
				c[n+2].b=d[i].b;
				c[i].a=d[n].a/2;
				continue;
			}
		}
		c[i].a=d[n].a-d[i-1].a;
		c[i].b=d[i].b;
	}
	int h=n;
	for(int i=1;i<=g;i++){
		if(c[i].a<=c[h].a && c[i].b!=c[n].b){
			ans+=c[i].a-c[i-1].a;
		}
		if(c[i].a>c[h].a){
			if(c[i].b!=c[h].b){
				ans+=c[h].a-c[i-1].a;
				h--;
			}
			while(c[i].a>c[h].a){
				if(c[i].b!=c[h].b){
					ans+=c[h].a-c[h+1].a;
				}
				h--;
			}
			if(c[i].b!=c[h].b){
				ans+=c[i].a-c[h+1].a;
			}
		}
		if(c[i].a==c[h].a){
			h--;
		}
	}
	if(c[n+2].a-c[g].a>c[g+1].a-c[g+2].a){
		for(int j=g+3;j<=n;j++){
			if(c[g+1].a-c[j].a>=c[n+2].a-c[g].a){
				if(c[n+2].b != c[j-1].b){
					ans+=c[j-1].a-c[g].a;		
				}
				break;
			}
			if(c[n+2].b != c[j-1].b){
				ans+=c[j-1].a-c[j].a;
			}
		}
	}
	std::cout<<ans;
}