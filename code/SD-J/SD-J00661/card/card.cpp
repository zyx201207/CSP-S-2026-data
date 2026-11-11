#include<bits/stdc++.h>
using namespace std;
int const N=3e6;
int n,m;
int a[N];
int q[N];
int cnt[N];
int top_();
int end_();
void push_(int x);
void pop_();
int size_();
void ere(int a,int b);void qing();
int find_(int x);
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=N;i++)
		q[i]=-1;
	for(int j=1;j<=n;j++){		
		for(int i=j;i<=n;i++){
			if(find_(a[i])==0){
				push_(a[i]);
			}	
			else{	
				ere(find_(a[i]),end_());
				push_(a[i]);
			}  
		}
		for(int k=1;k<=N;k++)
			cnt[q[k]]++;
		qing();
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}
int top_(){
	return q[1];
}
int end_(){
	for(int i=1;i<=N;i++)
		if(q[i]!=-1&&q[i+1]==-1){			
			return i;
				}
}
void push_(int x){
	for(int i=1;i<=N;i++)
		if(q[i]==-1){
	
			q[i]=x;
			return;
				}
}
void pop_(){
	for(int i=1;i<=N;i++)
		if(q[i]!=-1&&q[i+1]==-1){
			q[i]=-1;
			return;
				}
}
int size_(){
	int cntt;
	for(int i=1;i<=N;i++)
		if(q[i]!=-1){
			cntt++;
			
				}
	return cntt;
}
int find_(int x){
	for(int i=1;i<=N;i++)
		if(q[i]==x){
			return i;
			
				}
			return 0;
}
void ere(int a,int b){
	for(int i=a;i<=b;i++){
		q[i]=-1;
	}
}
void qing(){
	for(int i=1;i<=N;i++)
		q[i]=-1;
}

