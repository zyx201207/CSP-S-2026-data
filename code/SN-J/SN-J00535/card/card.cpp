#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int b[500005];
int a[300005],n,k;
void f(){
	int l=1;
	for(int i=1;i<=n;i++){
		int x=q.front();
		q.pop();
		q.push(x);
		for(int j=1;j<l;j++){
			if(x==b[j]){
				l=j;
				break;
			}
		}
		b[l]=x;
		l++;
		
	}
	for(int i=1;i<l;i++){
//		cout<<b[i]<<" ";
		a[b[i]]++;
	}
//	cout<<endl;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
//		cout<<x<<endl;
		q.push(x);
	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		f();
		int x=q.front();
		q.push(x);
		q.pop();
	}
//	cout<<1<<endl;
	for(int i=1;i<=k;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
