#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N],c[N],q[5],n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int i=1;i<=n;i++){
		    if(q[1]==b[i] || q[2]==b[i] || q[3]==b[i] || q[4]==b[i] || q[5]==b[i]){
				q[1]=q[2]=q[3]=q[4]=q[5]=0;
			}
			else{
				q[i]=b[i];
			}
		}
		for(int i=1;i<=5;i++){
			if(q[i]!=0){
				ans++;
			}
		}
		c[ans]++;
		q[1]=q[2]=q[3]=q[4]=q[5]=0;
		ans=0;
	}
	if(m==1){
		cout<<c[1];
	}
	if(m==2){
		cout<<c[1]<<" "<<c[2];
	}
	return 0;
}