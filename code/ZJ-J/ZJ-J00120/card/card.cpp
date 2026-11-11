#include<bits/stdc++.h>
using namespace std;
int a[200005],sum[300005];
queue <int> que1;
queue <int> que2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(i%2==1){
				int ok=0;
				while(!que1.empty()){
					int x=que1.front();
					que1.pop();
					if(x!=a[i]&&ok==0){
						que2.push(x);
					}else ok=1;
				}
				que2.push(a[i]);
			}else{
				int ok=0;
				while(!que2.empty()){
					int x=que2.front();
					que2.pop();
					if(x!=a[i]&&ok==0){
						que1.push(x);
					}else ok=1;
				}
				que1.push(a[i]);
			}
		}
		while(!que1.empty()){
			sum[que1.front()]++;
			que1.pop();
		}
		while(!que2.empty()){
			sum[que2.front()]++;
			que2.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
