#include <bits/stdc++.h>

int n,m,a[500010],c[500010],ans[300010],pt[500010];

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
		std::cin>>a[i];
	for(int i=1;i<=n;i++){
		int len=0;
		for(int j=i;j<=n;j++)
			c[++len]=a[j];
		std::map<int,int>mp;
		for(int j=1;j<=n;j++)
			mp[a[j]]=0;
		int nlen=0;
		for(int j=1;j<=len;j++){
			if(mp[c[j]]!=0){
				nlen=mp[c[j]];
				pt[nlen]=c[j];
				for(int k=nlen+1;k<=j;k++)
					mp[pt[k]]=0;
				for(int k=1;k<=nlen;k++)
					mp[pt[k]]=k;
			}
			else{
				pt[++nlen]=c[j];
				mp[c[j]]=nlen;
			}
		}
		for(int j=1;j<=nlen;j++)
			ans[pt[j]]++;
	}
	for(int i=1;i<=m;i++)
		std::cout<<ans[i]<<" ";
	std::cout<<"\n";
	return 0; 
}
