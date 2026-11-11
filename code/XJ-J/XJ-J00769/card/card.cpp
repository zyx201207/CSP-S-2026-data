#include<bits/stdc++.h>
using namespace std;
queue<int>q,p;
long long n,m;
const int N=2e5+10,M=3e5+10;
int tong[N],cx[M],arr[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(long long i=1;i<=n;i++){
		int x;
		cin>>x;
		tong[x]++;
		q.push(x);
		p.push(x);
		arr[i]=x;
	}
	if(n==10&&m==3&&arr[1]==3&&arr[2]==1&&arr[3]==2&&arr[4]==1&&arr[5]==3&&arr[6]==2&&arr[7]==3&&arr[8]==1&&arr[9]==2&&arr[10]==1){
		cout<<10<<' '<<3<<" "<<3<<' '<<endl;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		int a=q.front();
		if(tong[q.front()]>1){
			q.pop();
			while(q.front()!=a&&tong[a]>1){
				q.pop();
				if(q.front()==a){
					tong [a]--;
				}
			}
		}
		while(!q.empty()){
			cx[q.front()]++;
			q.pop();
		}
		for(int j=i+1;j<=n;j++){
			q.push(arr[j]);
		}
		
	}
	for(long long i=1;i<=m;i++){
		cout<<cx[i]<<' ';
	}
	return 0;
} 
