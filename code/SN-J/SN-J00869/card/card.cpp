#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	int stack[n+1]={},in_stack[m+1]={},stackhead=0,insum[m+1]={};
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(in_stack[a[j]]){
				while(stack[stackhead]!=a[j]){
					in_stack[stack[stackhead]]=0;
					stackhead--;
				}
			}
			else{
				in_stack[a[j]]=1;
				stack[++stackhead]=a[j];
			}
		}
		while(stackhead!=0){
			insum[stack[stackhead]]++;
			in_stack[stack[stackhead]]=0;
			stackhead--;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<insum[i]<<" ";
	}

	return 0;
}



