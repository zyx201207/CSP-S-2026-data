#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],h,x,y;
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	do{
		for(int i=1;i<=n;i++){
			q.push(a[i]);
			h++;
			for(int j=1;j<=k;i++)
				if(a[j]==a[i])
					for(int k=j;k<=n;k++)
						q.push(a[k]);
		}
		for(int i=1;i<=h;i++){
			if(a[i]==1)
				x++;
			if(a[i]==2)
				y++;
		}
	}while(!q.pop());
	cout<<x<<' '<<y;
	return 0;
}
