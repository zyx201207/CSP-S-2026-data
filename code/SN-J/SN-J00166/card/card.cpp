#include<bits/stdc++.h>
using namespace std;
long long n,cd[500001],m,pd[500001],q[500001],p[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>cd[i];
	}
	int ju=1;
	int ji=0;
	while(n--){
		ji=0;
		for(int i=0;i<n;i++){
			pd[i]=0;
			p[i]=0;
		}
		for(int i=ju-1;i<n;i++){
			pd[ji]=cd[i];
			for(int j=ji-1;j>=0;j--){
				if(pd[j]==pd[ji]){
					for(int k=j;k<ji;k++){
						pd[k]=0;
					}
				}
			}
			ji++;
		}
		for(int i=0;i<=n;i++){
			p[pd[i]]++;
		}
		for(int i=0;i<=n;i++){
			if(q[i]>0 and q[i]!=0){
				p[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]+1<<" ";
	}
	return 0;
}
