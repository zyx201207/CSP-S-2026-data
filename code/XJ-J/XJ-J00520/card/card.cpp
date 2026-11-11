#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],l[300005],vis[500005],k[300004],bg[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) l[i]=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=m;i++) k[i]=0;
	for(int i=1;i<=n;i++){
	    k[a[i]]++;
		bg[a[i]]=i;
		vector<int> s;
		s.push_back(a[i]);
		for(int j=i+1;j<=n;j++){
			s.push_back(a[j]);
			k[a[j]]++;
			if(k[a[j]]>1){
				for(int q=bg[a[j]];q<=j-1;q++) vis[q]=1;
				k[a[j]]=0;
			}
			if(vis[j]!=1){
				l[a[j]]++;
			}
		}
	}
	l[a[n]]=n;
	l[a[1]]++;
	for(int i=1;i<=m;i++){
	    cout<<l[i]<<" ";
	}
	return 0;
}