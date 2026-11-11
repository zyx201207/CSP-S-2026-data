#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],c[N];
vector<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=0;k<q.size();k++)
			    if(q[k]==a[j]){
			    	for(int l=k;l<q.size();l++)
			    	    q[l]=0;
			    	break;
				}
			q.push_back(a[j]);
		}
		for(int j=0;j<q.size();j++)
		    c[q[j]]++;
		q.clear();
	}
	for(int i=1;i<=m;i++)
	    printf("%d ",c[i]);
	return 0;
}
