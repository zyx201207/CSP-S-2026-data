#include<bits/stdc++.h>
using namespace std;
#define lint long long
struct node{
	bool a[40];
	bool y;
};
node q[200005];
lint n,m,ans,b[40];
int big;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		lint z;
		cin>>z;
		for(int j=0;z>>j > 0;j++){
			lint u;
			u=z>>j;
	//		cout<<u<<endl;
			if(u%2==1){
				q[i].a[j+1]=1;
				b[j+1]++;
				big=max(big,j+1);
			}
		}
	}
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=4;j++){
			cout<<q[i].a[j];
		}
		cout<<endl;
	}*/
	for(int i=big;i>=1;i--){
		lint cnt=0;
		for(int j=1;j<=n;j++){
			if(b[i]<m){
				break;
			}
			if(q[j].a[i]==1 && q[j].y==0){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=(1<<i-1);
			for(int j=1;j<=n;j++){
				if(q[j].a[i]==0){
					q[j].y=1;
				}
			} 
		}
	}
	cout<<ans;
	return 0;
}
