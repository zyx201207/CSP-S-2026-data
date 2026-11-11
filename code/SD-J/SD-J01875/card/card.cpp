#include<bits/stdc++.h>
using namespace std;
int n,m;
int const A=3e5+1;
int arr[A],st[A],brr[A];
stack<int> qu;
int main(){
	memset(arr,0,sizeof(arr));
	memset(brr,0,sizeof(brr));
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&st[i]);
	}
	for(int i=1;i<=n;++i){
		memset(brr,0,sizeof(brr));
		for(int j=i;j<=n;++j){
			if(brr[st[j]]==0){
				qu.push(st[j]);
				brr[st[j]]++;
			}else{
				brr[st[j]]++;
				while((brr[qu.top()]-1)==0){
					brr[qu.top()]=0;
					qu.pop();
				}
				brr[qu.top()]=1;
			}
		}
		for(int j=1;j<=n;++j) arr[j]+=brr[j];
	}
	for(int i=1;i<=m;++i){
		printf("%d ",arr[i]);
	}
	return 0;
}
