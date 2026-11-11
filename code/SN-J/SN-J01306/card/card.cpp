#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int n,m,raw[N],ans[N];
void solve(int a){
	int i=a,j=n-1,ni,nj,flag = 0,add[N];
	for(int i=a;i<n;i++){
		if(flag)break;
		for(int j=n-1;j>i;j--){
//			printf(" %d %d %d\n",i,j,raw[i] == raw[j]);
			if(raw[i] == raw[j]){
				ni = i;nj = j;
				flag = 1;
				break;
			}
		}
	}
	if(!flag)for(int i=a;i<n;i++)add[raw[i]] = 1;
	else{
		for(;ni>=a;ni--){
//			printf("ni = %d,  %d\n",ni,raw[ni]);
			add[raw[ni]] = 1;
		} 
		for(;nj<n;nj++){
//			printf("nj = %d,  %d\n",nj,raw[nj]);
			add[raw[nj]] = 1;
		} 
	}

	for(int i=1;i<=m;i++){
		ans[i]+=add[i];
	}
//	for(int i=1;i<=m;i++)cout<<add[i]<<" ";
//	puts("");
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>raw[i];
	}
	for(int i=0;i<n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	
}
