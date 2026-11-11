#include<bits/stdc++.h>
using namespace std;
const int N=5e5+66,M=3e5+66;
int n,m,a[N],hs[N];
int p[M]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	// 真理： 正解肯定找相同的 
	scanf("%d %d",&n,&m);
	int f=0;
	for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	if(a[i]<a[i-1]) f=1;
}
	if(n<=500){
	for(int i=n;i>=1;i--){
	if(p[a[i]]==0) p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){// 第i轮 
	priority_queue<int>q;
    for(int j=i;j<=n;j++){// 到第j个
	q.push(a[j]);
	if(p[a[j]]!=j) j=p[a[j]]; 
	}
	int now=-1;
	while(!q.empty()){
	if(q.top()!=now){
	hs[q.top()]++;
	now=q.top();
	q.pop();
	}
	}
	}
	for(int i=1;i<=m;i++){
	printf("%d ",hs[i]);
	}
	}
	else if(f==0){
	int q[N];
	for(int i=1;i<=m;i++) q[i]=0;
	for(int i=n;i>=1;i--){
	if(q[a[i]]==0){
	q[a[i]]=i;	
	}
	}
	for(int i=1;i<=m;i++){
	printf("%d ",q[i]);
	}
	}
	else{
	for(int i=n;i>=1;i--){
	if(p[a[i]]==0) p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){// 第i轮 
	priority_queue<int>q;
    for(int j=i;j<=n;j++){// 到第j个
	q.push(a[j]);
	if(p[a[j]]!=j) j=p[a[j]]; 
	}
	int now=-1;
	while(!q.empty()){
	if(q.top()!=now){
	hs[q.top()]++;
	now=q.top();
	q.pop();
	}
	}
	}
	for(int i=1;i<=m;i++){
	printf("%d ",hs[i]);
	}
	}
	return 0;
} 
