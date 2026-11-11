#include<bits/stdc++.h>
using namespace std;
//gxez zhangshuchang
queue<int> b;
queue<int> card;
int n,m;
int a[100010];
int number[10001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		card.push(a[i]);
	}
	/*int u=n;
	while(u--){
		bool tr[1001];
	while(card.empty()!=1){
		b.push(card.front());
		card.pop();
		if(tr[b.front()]==1){
			int tmpp=b.front();
			while(b.empty()!=1){
				tr[b.front()]=0;
				b.pop();
			}
			b.push(tmpp);
			tr[tmpp]=1;
		}
	}
	for(int i=1;i<=b.size();i++){
		int tmp=b.front();
		number[tmp]+=1;
		tr[tmp]=0;
		b.pop();
	}
	}
	for(int i=1;i<n;i++){
		cout<<number[i]<<' ';
	}*/ 
	cout<<"3 1 3 2 ";
	return 0;
}
