#include<bits/stdc++.h>
using namespace std;
int num,sum,number[200005],number2[200005],ans=0,lin,tot,node=1;
void fcd(int x){
	if(lin!=0){
		for(int j=x+1;j<=num;j++){
			number2[node]=j;
			node++;
			fcd(j);
		}
	}
	else {
		tot=number2[1];
		for(int k=2;k<=node;k++){
			tot=(tot & number2[k]);
		}
		ans=max(ans,tot);
		node--;
		return ;
	}
	node--;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>num>>sum;
	lin=sum-1;
	for(int i=1;i<=num;i++){
		cin>>number[i];
	}
	for(int i=1;i<=num-sum+1;i++){
		number2[node]=i;
		node++;
		fcd(i);
	}
	cout<<ans;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
