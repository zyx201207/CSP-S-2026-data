#include<iostream>
#include<deque> 
using namespace std;

int n,m,a[200010],q[200010],js[200010];
bool b[200010];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		for(int i=1,w=1;(n-i)>=t;i++){
			if(b[a[i]]==1){
				while(q[w]!=a[i]){
					b[q[w]]=0;
					w--;
				}
			}
			b[a[i]]=1;
			q[w]=a[i];
			w++;
		}
		for(int i=1;i<=n;i++){
			if(b[i]==1)js[i]++;
			b[i]=0;
		}
	}
	for(int i=1;i<m;i++)cout<<js[i]<<' ';
	cout<<n;
	return 0;
}
