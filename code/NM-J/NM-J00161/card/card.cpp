#include<iostream>
#include<algorithm> 
#include<cstring>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b,c=1,d=1,e,f[500000],h[500000],i,g[500000]={0};
	cin>>a>>b;
	while(c<=a){
		cin>>f[c];
		c++;
	}
	while(d<=a){
		e=d,i=1;;
		memset(h,0,sizeof(h));
		while(e<=a){
			h[f[e]]++;
			if(h[f[e]]==2){
				memset(h,0,sizeof(h));
				h[f[e]]++;	
			}
			e++;
		}
		while(i<=b){
			if(f[i]==1)
			g[f[i]]++;
			i++;
		}
		d++;
	}
	i=1;
	while(i<=b){
		cout<<g[i]<<" ";
		i++;
	}
	return 0;
}
